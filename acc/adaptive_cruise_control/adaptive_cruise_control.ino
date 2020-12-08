void forward()
{

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  //delay(1000);
}

void backward()
{

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(1000);
}

void left()
{

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  delay(1000);
}

void right()
{

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(1000);
}

void stop()
{

  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
  //delay(1000);
}

void rotateleft()
{
  motorspeedA = 80;
  motorspeedB = 80;
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(600);
  //while((distancef('M') > 20) && (distancef('L') > 20) && (distancef('R') > 20));
  
}
void rotateright()
{
  motorspeedA = 100;
  motorspeedB = 100;
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(600);
  //while((distancef('M') > 20) && (distancef('L') > 20) && (distancef('R') > 20));
  
}
int minof(int distM,int distL,int distR)
{
  return (min(min(distM,distL),distR));
}
//map(value, fromLow, fromHigh, toLow, toHigh)

//for first sensor arrangement

void oa()   
{
  distM = distancef('M');
  distR = distancef('R');
  distL = distancef('L');
  if((distM < 10)||(distL < 10)||(distR < 10)) 
  {
    if((distM < 17)&&(distL < 17)&&(distR < 17))
    {
      while((distancef('M') > 10) && (distancef('L') > 10) && (distancef('R') > 10))
      {
        stop(); 
        motorspeedA = 150;
        motorspeedB = 150;
        rotateleft();
      }
    }
  }
  else if(( (distM < 45) && (distM > 10)) || ( (distL < 45) && (distL > 10)) || ( (distR < 45) && (distR > 10)) )
  {
    forward();
    motorspeedA = map(minof(distM,distL,distR),10,45,71,100);
    motorspeedB = motorspeedA;
  }
  else if((distM > 45)&&(distL > 45)&&(distR > 45)) 
  {
    forward();
    motorspeedA = 200;
    motorspeedB = 200;
  }
    
  }
//for sensor arrangement 1

 void ob()
{
  if((distancef('M') > 50))
  {
    forward();
    motorspeedA = 200;
    motorspeedB = 200;
  }
  else if(( distancef('M') < 51) && (distancef('M') > 35))
  {
    forward();
    motorspeedA = map(distancef('M'),35,50,71,100);
    motorspeedB = motorspeedA;
  }
  else if( (distancef('M') < 35) && (distancef('M') > 17) )
  {
    motorspeedA = 70;
    motorspeedB = 70;
    distancef('L')>distancef('R')? left():right();
  }
  else if( distancef('M') < 17)
  {
    while((distancef('M') > 17) || (distancef('L') > 17) || (distancef('R') > 17))
    {
      //stop(); 
      motorspeedA = 200;
      motorspeedB = 200;
      rotateleft();
        
    }
      
  }
}

// for sensor arrangement 2 (obstacle avoidance)
void oc()
{
  if((distancef('M') < 15))
  {
    stop();
    if(distancef('L')>15)
    {
      rotateleft();
      stop();
    }
    else if(distancef('R')>15)
    {
      rotateright();
      stop(); 
    }
    else
    {
      backward(); 
    }
  }
  else if(( distancef('M') < 51) && (distancef('M') > 15))
  {
    forward();
    motorspeedA = map(distancef('M'),15,50,71,150);
    motorspeedB = motorspeedA;
  }
  else if( (distancef('M') > 51) )
  {
    forward();
    motorspeedA = 200;
    motorspeedB = 200;
    //distancef('L')>distancef('R')? left():right();
  }
  
}
  
