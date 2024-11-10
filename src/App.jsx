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
    color: "black",
    borderColor: "black",
    fontSize: "80px",
    textAlign: "center"
  }

  return (
    <div className='frame'>
      <TicTacToe area={3} players={['O', 'X']} checkWinner={getWinner} turnCounter={setTurn} boardStyle={board} buttonStyle={button} />
    </div>
  )
}

export default App
