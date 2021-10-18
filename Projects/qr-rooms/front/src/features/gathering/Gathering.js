/* eslint-disable react-hooks/exhaustive-deps */
import { useEffect, useState } from 'react'
import { useHistory, useParams } from 'react-router'
import Header from '../../components/header/Header'
import { socket } from '../../lib/socket'
import Attendees from './Attendees'
import GatheringQR from './GatheringQR'
import SocialForm from './SocialForm'

const Gathering = () => {
  const { gatheringId } = useParams()
  const history = useHistory()

  const [gathering, setGathering] = useState({})
  const [socialAdded, setSocialAdded] = useState(false)

  useEffect(() => {
    // If query param is null -> create room
    // If query param is invalid -> display error, suggest creating a room
    // If query param is valid -> join room

    if (gatheringId) {
      // Try to join room
      socket.emit('gathering:join', gatheringId)
    } else {
      // Create room
      socket.emit('gathering:create')
    }
    socket.on('gathering', data => {
      setGathering(data)
    })
  }, [])

  useEffect(() => {
    if (!gatheringId && gathering.id) {
      history.push(`/${gathering.id}`)
    }
  }, [gathering])

  if (!gathering) return (<div>Loading</div>) 

  return (
    <div className='container' style={{ maxWidth: '844px' }}>
      <Header />
      <div className='text-center'>
        {!socialAdded && <SocialForm socialAddedQuery={() => setSocialAdded(true)}/>}
        <GatheringQR gatheringId={gatheringId}/>
        <Attendees data={gathering.attendees} />
      </div>
    </div>
  )
}

export default Gathering
