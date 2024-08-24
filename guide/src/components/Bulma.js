
const Column = (props) => {return (<div className={`column ${props.className !== undefined ? props.className: ''}`}>{props.children}</div>)}
const Columns = (props) => {return (<div className={`columns ${props.className !== undefined ? props.className: ''}`}>{props.children}</div>)}

export {Column, Columns}