//@ts-check
const fs = require("fs");

class Cell {
    constructor(str = "") {
        this.str = str;
    }
}

class Line {
    constructor() {
        /** @type {Cell[]} */
        this.cells = [];
    }

    /**
     * @param {number} index
     * @param  {...string} items
     */
    insert(index, ...items) {
        const cells = items.map((item) => new Cell(item));
        this.cells.splice(index, 0, ...cells);
    }

    toString() {
        return this.cells
            .map((cell) => cell.str)
            .join("")
            .trimEnd();
    }
}

class BlockLines {
    constructor() {
        /** @type {Line[]} */
        this.lines = [];
        this.isRaw = true;
    }

    addLine(raw = "") {
        const line = new Line();
        if (this.isRaw) {
            const cell = new Cell();
            cell.str = raw;
            line.cells = [cell];
        } else {
            for (const part of raw.split(/\s+/)) {
                const cell = new Cell();
                cell.str = part;
                line.cells.push(cell);
            }
        }
        this.lines.push(line);
    }

    toString() {
        return this.lines.map((line) => line.toString()).join("\n");
    }
}

class File {
    constructor() {
        /** @type {BlockLines[]} */
        this.blocks = [];
    }

    toString() {
        return this.blocks.map((b) => b.toString()).join("\n");
    }
}

/**
 * @param {string} filepath
 */
function readFile(filepath) {
    const content = fs.readFileSync(filepath, "utf8");
    const lines = content.split("\n");
    const file = new File();

    let currentBlock = new BlockLines();

    for (let i = 0; i < lines.length; i++) {
        const line = lines[i];

        if (line.includes("//--- begin of auto align")) {
            currentBlock.addLine(line);
            file.blocks.push(currentBlock);

            currentBlock = new BlockLines();
            currentBlock.isRaw = false;
            continue;
        }

        if (line.includes("//--- end of auto align")) {
            file.blocks.push(currentBlock);

            currentBlock = new BlockLines();
            currentBlock.addLine(line);
            continue;
        }

        currentBlock.addLine(line);
    }

    file.blocks.push(currentBlock);

    return file;
}

/**
 * @param {File} file
 * @returns
 */
function computeCols(file) {
    /** @type {number[]} */
    const maxCols = [];

    for (const block of file.blocks) {
        if (block.isRaw) {
            continue;
        }
        for (const line of block.lines) {
            for (let i = 0; i < line.cells.length; i++) {
                const cellLength = line.cells[i].str.length;
                if (i >= maxCols.length) {
                    maxCols.push(cellLength);
                } else {
                    maxCols[i] = Math.max(maxCols[i], cellLength);
                }
            }
        }
    }

    return maxCols;
}

/**
 * @param {File} file
 * @param {number[]} cols
 */
function alignFile(file, cols) {
    for (const block of file.blocks) {
        if (block.isRaw) {
            continue;
        }
        for (const line of block.lines) {
            if (line instanceof Line) {
                for (let i = 0; i < line.cells.length; i++) {
                    if (i < cols.length) {
                        line.cells[i].str = line.cells[i].str.padEnd(
                            cols[i] + 2,
                            " "
                        );
                    }
                }
            }
        }
    }
}

/**
 * @param {string} filepath
 * @param {File} file
 */
function writeFile(filepath, file) {
    let content = file.toString();

    fs.writeFileSync(filepath, content);
}

const filepath = "keymap.c";

try {
    const file = readFile(filepath);

    for (const block of file.blocks) {
        if (block.isRaw) {
            continue;
        }
        for (const [i, line] of block.lines.entries()) {
            for (const cell of line.cells) {
                cell.str = cell.str.trim();
            }
            if (i <= 2) {
                line.insert(7, "", "");
            } else if (i === 4) {
                line.insert(0, "", "");
            }
        }
    }

    const cols = computeCols(file);
    console.log("cols:", cols);

    alignFile(file, cols);
    writeFile(filepath, file);
} catch (error) {
    console.error(error);
}
