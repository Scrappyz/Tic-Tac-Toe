import React, { useState, useEffect, useRef } from "react";
import PropTypes from "prop-types";

function TicTacToe(props) {
    // Initialize board state as a 2D array of empty strings
    const [board, setBoard] = useState(
        Array.from(Array(props.area).fill(), () => Array(props.area).fill(' '))
    );

    // State for tracking the current player’s turn
    const [player, setPlayer] = useState(0);
    
    const [turnCount, setTurnCount] = useState(1);

    // Construct the grid template style for the board layout
    const templateColumn = Array(props.area).fill(props.buttonStyle.height).join(' ');
    const templateRow = Array(props.area).fill(props.buttonStyle.width).join(' ');

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

    let winner = getWinner();

    // Check for a winner whenever the board updates
    useEffect(() => {
        winner = getWinner();
        if(winner !== null) {
            props.checkWinner(winner);
        }
    }, [board]); // Run effect only when board changes

    useEffect(() => {
        props.turnCounter(turnCount);
    }, [turnCount]);

    useEffect(() => {
        setBoard(Array.from(Array(props.area).fill(), () => Array(props.area).fill(' ')));
        setTurnCount(1);
        setPlayer(0);
    }, [props.resetKey])

    useEffect(() => {
        props.currentPlayer(props.players[player]);
    }, [player]);

    // Handle button clicks to update board state
    const handleClick = (row, col) => {
        // If the cell is already filled, do nothing
        if (board[row][col] !== ' ') return;

        if(winner !== null) return;

        // Update the board with the current player’s symbol
        const newBoard = board.map((rowArr, i) =>
            rowArr.map((cell, j) => (i === row && j === col ? props.players[player] : cell))
        );

        setBoard(newBoard);
        setPlayer((player + 1) % props.players.length);
        setTurnCount(turnCount + 1);
    }

    const boardStyle = {
        ...props.boardStyle,
        display: "grid",
        gridTemplateColumns: templateColumn,
        gridTemplateRows: templateRow
    }

    const buttonStyle = props.buttonStyle;

    return (
        <div style={boardStyle}>
            {board.map((row, rowIndex) => (
                row.map((cell, colIndex) => (
                    <button
                        type="button"
                        style={buttonStyle}
                        onClick={() => handleClick(rowIndex, colIndex)}
                    >
                        {cell}
                    </button>
                ))
            ))}
        </div>
    );
}

TicTacToe.propTypes = {
    area: PropTypes.number,
    players: PropTypes.arrayOf(PropTypes.string),
    currentPlayer: PropTypes.func,
    resetKey: PropTypes.bool,
    checkWinner: PropTypes.func,
    turnCounter: PropTypes.func,
    boardStyle: PropTypes.object,
    buttonStyle: PropTypes.object
};

TicTacToe.defaultProps = {
    area: 3,
    players: ['O', 'X'],
    resetKey: false,
    boardStyle: {
        display: "grid",
        height: "300px",
        width: "300px"
    },
    buttonStyle: {
        color: "black",
        backgroundColor: "transparent",
        borderColor: "black",
        fontSize: "80px"
    }
};

export default TicTacToe;
