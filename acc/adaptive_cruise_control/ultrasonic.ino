int distancef(char RML)
{
  switch(RML)
  {
    case 'R':
              trigPin=TR;
              echoPin=ER;
              break;
   case 'M':
              trigPin=TM;
              echoPin=EM;
              break;
   case 'L':
              trigPin=TL;
              echoPin=EL;
              break;
   default:
              break;
            
  }
  
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  
//  Serial.print(distance);
//  Serial.print(RML);
//  Serial.print("            ");
  return distance;
  

}
