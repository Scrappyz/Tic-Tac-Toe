import { useState, useRef } from 'react'
import './App.css'
import Board from './components/Board/Board.jsx'

function App() {
  const [winner, setWinner] = useState(null);

  const getWinner = (winner) => {
    setWinner(winner);
  }

  return (
    <>
      <Board area={3} checkWinner={getWinner}/>
    </>
  )
}

export default App
