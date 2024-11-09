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
    height: "200px",
    width: "200px"
  }

  const button = {
    backgroundColor: "transparent",
    color: "black",
    borderColor: "purple",
    fontSize: "80px"
  }

  return (
    <>
      <TicTacToe area={2} players={['O', 'X']} checkWinner={getWinner} turnCounter={setTurn} boardStyle={board} buttonStyle={button} />
    </>
  )
}

export default App
