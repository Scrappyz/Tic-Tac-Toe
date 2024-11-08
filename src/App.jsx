import { useState } from 'react'
import './App.css'
import Board from './components/Board/Board.jsx'

function App() {
  const [count, setCount] = useState(0)

  return (
    <>
      <Board area={2} />
    </>
  )
}

export default App
