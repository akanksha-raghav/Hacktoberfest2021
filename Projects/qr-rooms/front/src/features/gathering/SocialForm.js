import { useState } from 'react'
import { Button, Form } from 'react-bootstrap'
import { socket } from '../../lib/socket'

const SocialForm = ({ socialAddedQuery }) => {
  const [name, setName] = useState('')
  const [snapchat, setSnapchat] = useState('')
  const [instagram, setInstagram] = useState('')

  const handleSubmit = e => {
    e.preventDefault()
    socket.emit('gathering:add', {name, snapchat, instagram})
    socialAddedQuery()
  }

  return ( 
    <Form onSubmit={handleSubmit}>
      <Form.Control type='input' placeholder='name' onChange={(e) => setName(e.target.value)} />
      <Form.Control type='input' placeholder='instagram username' onChange={(e) => setInstagram(e.target.value)} />
      <Form.Control type='input' placeholder='snapchat username' onChange={(e) => setSnapchat(e.target.value)} />
      <Button type='submit' className='w-100'>
        Add your socials
      </Button>
    </Form>
   )
}
 
export default SocialForm