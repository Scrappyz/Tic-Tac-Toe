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
    alert(turn);
  }

  return (
    <>
      <TicTacToe area={2} players={['O', 'X']} checkWinner={getWinner} turnCounter={setTurn} />
    </>
  )
}

export default App
