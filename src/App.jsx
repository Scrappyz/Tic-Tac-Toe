import { useState } from 'react'
import './App.css'
import TicTacToe from './components/TicTacToe/TicTacToe.jsx';

function App() {
  let winner = null;
  let turn = 1;

  // Callback function to get the current winner
  const getWinner = (winningPlayer) => {
    winner = winningPlayer;
    alert("Winner: " + winner);
  }

  // Callback function to track turn
  const setTurn = (n) => {
    turn = n;
    // alert(turn);
  }

  const board = {
    padding: "0px",
    columnGap: "0px",
    rowGap: "0px"
  }

  const button = {
    backgroundColor: "transparent",
    color: "white",
    borderColor: "white",
    borderWith: "20px",
    borderRadius: "3px",
    fontSize: "80px",
    textAlign: "center"
  }

  return (
    <div className='frame'>
      <div className="tictactoe-container">
        <div className='game-container'>
        <TicTacToe area={3} players={['O', 'X']} checkWinner={getWinner} turnCounter={setTurn} boardStyle={board} buttonStyle={button} />
          <div className='turn-container'>
            <p>Turn 1</p>
          </div>
        </div>
        <div className='button-container'>
          <button>Reset</button>
        </div>
      </div>
    </div>
  )
}

export default App
