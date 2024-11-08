import React, { useState } from "react";
import PropTypes from "prop-types";
import './Board.css';

function Board(props) {
    // Initialize board state as a 2D array of empty strings
    const [board, setBoard] = useState(
        Array.from(Array(props.area).fill(), () => Array(props.area).fill(' '))
    );

    // State for tracking the current player’s turn
    const [player, setPlayer] = useState(0);

    // Construct the grid template style for the board layout
    const templateColumn = Array(props.area).fill(props.columnWidth).join(' ');
    const templateRow = Array(props.area).fill(props.rowHeight).join(' ');

    const getWinner = () => {
        let winner = null;
        for(let i = 0; i < board.length(); i++) {
            for(let j = 1; j < board.length(); j++) {
                if(board[i][j] !== board[i][j-1]) {
                    break;
                }
            }
        }

        for(let j = 0; j < board.length(); j++) {
            for(let i = 1; i < board.length(); i++) {
                if(board[i][j] !== board[i-1][j]) {
                    return null;
                }
            }
        }

        for(let i = 1; i < board.length(); i++) {
            let j = i;
            if(board[i][j] !== board[i-1][j-1]) {
                return null;
            }
        }

        for(let i = 1; i < board.length(); i++) {
            let j = i;
            if(board[i][j] !== board[i-1][j+1]) {
                return null;
            }
        }
    }

    // Handle button clicks to update board state
    const handleClick = (row, col) => {
        // If the cell is already filled, do nothing
        if (board[row][col] !== ' ') return;

        // Update the board with the current player’s symbol
        const newBoard = board.map((rowArr, i) =>
            rowArr.map((cell, j) => (i === row && j === col ? props.players[player] : cell))
        );

        setBoard(newBoard);

        

        // Move to the next player, cycling back to the first player if needed
        setPlayer((player + 1) % props.players.length);
    }

    return (
        <div className="board" style={{ gridTemplateColumns: templateColumn, gridTemplateRows: templateRow }}>
            {board.map((row, rowIndex) => (
                row.map((cell, colIndex) => (
                    <button
                        type="button"
                        className="board-btn"
                        onClick={() => handleClick(rowIndex, colIndex)}
                    >
                        {cell}
                    </button>
                ))
            ))}
        </div>
    );
}

Board.propTypes = {
    area: PropTypes.number,
    players: PropTypes.arrayOf(PropTypes.string),
    columnWidth: PropTypes.string,
    rowHeight: PropTypes.string
};

Board.defaultProps = {
    area: 3,
    players: ['O', 'X'],
    columnWidth: "100px",
    rowHeight: "100px",
    winner: null
};

export default Board;
