import { Card } from "react-bootstrap"

const Attendees = ({ data: attendees }) => {
  return ( 
    <div>
      {attendees && attendees.map((attendee) => (
        <Card className='mb-3'>
          <Card.Body>
            {attendee.name && 
              <div>
                Name: {attendee.name}
              </div>
            }
            {attendee.snapchat && 
              <div>
                Snapchat: <a href={`https://www.snapchat.com/add/${attendee.snapchat}`} target="_blank" rel="noreferrer">{attendee.snapchat}</a>
              </div>
            }
            {attendee.instagram && 
              <div>
                Instagram: <a href={`https://www.instagram.com/${attendee.instagram}`} target="_blank" rel="noreferrer">{attendee.instagram}</a>
              </div>
            }
          </Card.Body>
        </Card>
      ))}
    </div>
  )
}
 
export default Attendees