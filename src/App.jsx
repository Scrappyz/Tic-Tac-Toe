import { useState } from 'react'
import './App.css'
import Board from './components/Board/Board.jsx'

function App() {
  const [winner, setWinner] = useState(null);
  const [turnCount, setTurnCount] = useState(1);

  const getWinner = (winner) => {
    setWinner(winner);
    alert(winner);
  }

  const setTurn = (n) => {
    setTurnCount(n);
    alert(turnCount);
  }

  return (
    <>
      <Board area={3} players={['O', 'X', 'H']} checkWinner={getWinner} turnCounter={setTurn} />
    </>
  )
}

export default App
