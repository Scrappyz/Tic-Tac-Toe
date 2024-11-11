import { useState } from 'react'
import './App.css'
import TicTacToe from './components/TicTacToe/TicTacToe.jsx';

function App() {
  let winner = null;
  let turn = 1;
  const [resetKey, setResetKey] = useState(0);

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

  // Updates infinitely
  const resetBoard = () => {
    setResetKey(prev => prev + 1);
  }

  const board = {
    height: "300px",
    width: "300px"
  }

  const button = {
    backgroundColor: "transparent",
    color: "white",
    borderColor: "white",
    borderWith: "20px",
    borderRadius: "3px",
    fontSize: "80px",
    textAlign: "center",
    height: "100px",
    width: "100px"
  }

  return (
    <div className='frame'>
      <div className="tictactoe-container">
        <div className='game-container'>
        <TicTacToe area={3} players={['O', 'X']} resetKey={resetKey} checkWinner={getWinner} turnCounter={setTurn} boardStyle={board} buttonStyle={button} />
          <div className='turn-container'>
            <p>Turn 1</p>
          </div>
        </div>
        <div className='button-container'>
          <button onClick={() => resetBoard()}>Reset</button>
        </div>
      </div>
    </div>
  )
}

export default App
