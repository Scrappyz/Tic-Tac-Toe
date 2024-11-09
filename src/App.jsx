import { useState } from 'react'
import './App.css'
import TicTacToe from './components/TicTacToe/TicTacToe.jsx';

function App() {
  const [winner, setWinner] = useState(null);
  const [turnCount, setTurnCount] = useState(1);

  // Callback function to get the current winner
  const getWinner = (winner) => {
    setWinner(winner);
    alert(winner);
  }

  // Callback function to track turn
  const setTurn = (n) => {
    setTurnCount(n);
    alert(turnCount);
  }

  return (
    <>
      <TicTacToe area={4} players={['O', 'X', 'H']} checkWinner={getWinner} turnCounter={setTurn} />
    </>
  )
}

export default App
