import React, {useState} from "react"
import PropTypes from "prop-types"
import './Board.css'

function Board(props) {
    const board = [];
    let template_column = ''

    for(let i = 0; i < props.area; i++) {
        template_column = template_column.concat('auto')
        if(i < props.area - 1) {
            template_column = template_column.concat(' ')
        }
    }

    for(let i = 0; i < props.area; i++) {
        board.push([]);
        for(let j = 0; j < props.area; j++) {
            board[i].push(' ');
        }
    }

    return (
        <div className="board" style={{gridTemplateColumns: template_column}}>
            {board.map((row) => (
                row.map((btn) => (
                    <button type="button" className="board-btn">{btn}</button>
                ))
            ))}
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