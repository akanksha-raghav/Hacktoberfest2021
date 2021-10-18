import './main.scss'
import { BrowserRouter as Router, Switch, Route } from 'react-router-dom'
import Gathering from './features/gathering/Gathering'

function App() {
  return (
    <div className='App'>
      <Router>
        <Switch>
          <Route path='/:gatheringId?' component={Gathering} />
        </Switch>
      </Router>
    </div>
  )
}

export default App
