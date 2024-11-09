import React, { useState, useEffect, useRef } from "react";
import PropTypes from "prop-types";
import './Board.css';

function Board(props) {
    // Initialize board state as a 2D array of empty strings
    const [board, setBoard] = useState(
        Array.from(Array(props.area).fill(), () => Array(props.area).fill(' '))
    );

    // State for tracking the current player’s turn
    const [player, setPlayer] = useState(0);
    
    const [turnCount, setTurnCount] = useState(1);

    // Construct the grid template style for the board layout
    const templateColumn = Array(props.area).fill(props.columnWidth).join(' ');
    const templateRow = Array(props.area).fill(props.rowHeight).join(' ');

    const getWinner = () => {
        const size = board.length;

        // Check rows
        for(let i = 0; i < size; i++) {
            if (board[i].every(cell => cell === board[i][0] && cell !== ' ')) {
                return board[i][0];
            }
        }

        // Check columns
        for(let j = 0; j < size; j++) {
            if (board.every(row => row[j] === board[0][j] && row[j] !== ' ')) {
                return board[0][j];
            }
        }

        // Check main diagonal
        if(board.every((row, i) => row[i] === board[0][0] && row[i] !== ' ')) {
            return board[0][0];
        }

        // Check anti-diagonal
        if(board.every((row, i) => row[size - 1 - i] === board[0][size - 1] && row[size - 1 - i] !== ' ')) {
            return board[0][size - 1];
        }

        return null; // No winner
    };

    // Check for a winner whenever the board updates
    useEffect(() => {
        const winner = getWinner();
        if(winner !== null) {
            props.checkWinner(winner);
        }
    }, [board]); // Run effect only when board changes

    useEffect(() => {
        props.turnCounter(turnCount);
    }, [turnCount]);

    // Handle button clicks to update board state
    const handleClick = (row, col) => {
        // If the cell is already filled, do nothing
        if (board[row][col] !== ' ') return;

        // Update the board with the current player’s symbol
        const newBoard = board.map((rowArr, i) =>
            rowArr.map((cell, j) => (i === row && j === col ? props.players[player] : cell))
        );

        setBoard(newBoard);
        setPlayer((player + 1) % props.players.length);
        setTurnCount(turnCount + 1);
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
    rowHeight: PropTypes.string,
    checkWinner: PropTypes.func,
    turnCounter: PropTypes.func
};

Board.defaultProps = {
    area: 3,
    players: ['O', 'X'],
    columnWidth: "100px",
    rowHeight: "100px"
};

export default Board;
