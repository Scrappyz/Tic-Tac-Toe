import React from "react"
import PropTypes from "prop-types"
import './Button.css'

function Board(props) {
    const board = [];

    for(let i = 0; i < props.area; i++) {
        board.push()
    }

    return (
        <div className="board">
            <button type="button" className="board-btn">1</button>
            <button type="button" className="board-btn">2</button>
            <button type="button" className="board-btn">3</button>
            <button type="button" className="board-btn">4</button>
            <button type="button" className="board-btn">5</button>
            <button type="button" className="board-btn">6</button>
            <button type="button" className="board-btn">7</button>
            <button type="button" className="board-btn">8</button>
            <button type="button" className="board-btn">9</button>
        </div>
    );
}

Board.propTypes = {
    area: PropTypes.number
}

Board.defaultProps = {
    area: 3
}

export default Board