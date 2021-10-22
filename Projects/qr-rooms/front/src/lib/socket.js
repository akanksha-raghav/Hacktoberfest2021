import io from 'socket.io-client'
import { socketUrl } from '../constants'

export const socket = io(socketUrl)
