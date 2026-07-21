#include "Particle.h"

Particle::Particle(std::string line)
{
    vMax = 1;   pBest = NULL;
        std::string input;
        std::stringstream stream(line);

 
    std::getline(stream, input, '|'); 
    std::string posComponent = input.substr(2,input.size()-4);
     
    std::getline(stream,input,'|') ;
    std::string velComponent = (input.substr(2, input.size() - 4));
                  
         std::getline(stream,input,'|');
         std::stringstream s0(input);
         double outputw ;
         s0 >> outputw;
         w = outputw;

         std::getline(stream,input,'|');
         std::stringstream s1(input);
         double outputc1 ;
         s1 >> outputc1;
         c1 = outputc1;

         std::getline(stream,input,'|');
         std::stringstream s2(input);
         double outputc2 ;
         s2 >> outputc2;
         c1 = outputc2;
     
        int count = 1;
        for (int i = 0;i < posComponent.size();++i) {
        if (posComponent[i] == ',') {
            ++count;
        } }
       // position.array = new double[count];
        //velocity.array = new double[count];

        std::stringstream posStream(posComponent);
        position.Vector(posStream);
       /* for (int i =0;i < count;++i)
        {
        std::getline(posStream, input, ',');
        std::stringstream s3(input);
         double output1 ;
         s3 >> output1;
         position.array[i] = output1;
         }*/
        
        
          std::stringstream velStream(velComponent);
          velocity.Vector(velStream);
        /*for (int i =0;i < count;++i) 
        {
        std::getline(velStream, input, ',');
         std::stringstream s4(input);
         double output2 ;
         s4 >> output2;
         velocity.array[i] = output2; 
         }*/
            // }
}

Particle::Particle(const Particle& other)
{   
    this->pBest = other.pBest;
    this->w = other.w;
    this->c1 = other.c1;
    this->c2 = other.c2;

    this->position = other.position;
    this->velocity = other.velocity;

    if (other.position != NULL)
    {
       int posSize = other.Vector::getSize();
       this->position = new Vector[posSize];
       this->velocity = new Vector[posSize];  

       for (int s=0; s < posSize;++s)
       {
          this->position[s] = other.position[s];
          this->velocity[s] = other.velocity[s];
       }    
    }    
}

Particle::~Particle()
{
    delete position;
    delete velocity;
    delete pBest;
}
    
void Particle::updateParticle(const Particle& gBest) 
{
    for (int i = 0; i > 0 and i < position->getSize()  ; i++ )
    {   double veloutput; 
        if (pBest != NULL)
        {
             velocity.updateParticle(i) = w * velocity.get(i) + c1 * (pBest.array(i) - position.get(i)) + c2 * (gBest.position->operator.get(i) - position.get(i));
        } else {
            velocity = w * velocity[i] + c2 * (gBest.position->operator[i] - position[i]);
        }

       if (velocity[i] > vMax) 
       {
            velocity[i] = vMax;
        } else if (velocity[i] < -vMax) 
        {
            velocity[i] = -vMax;
        }
        position[i] =  position[i] + velocity[i];
   }
}

const Vector& Particle::getVelocity() const
{

    return (*velocity);
}

const Vector& Particle::getPosition() const
{

    return (*position);
}

const Vector* Particle::getPBest() const
{

    return (pBest);
}

void Particle::setVMax(double vMax){
    this->vMax = vMax;
}

double Particle::evaluate(const Function& function)
{

  if (pBest != NULL)
  {
    double currentValue = function.evaluate(*position);
    double pBestValue = function.evaluate(*pBest);

    if (currentValue < pBestValue)
    {   delete pBest; 
     pBest = new Vectror(*position) ; 
     }else
     pBest =new Vector(*position); 
  }
  return (currentValue);
    
}

bool Particle::equal(const Particle& other) const
{
    if ((this->*position != other.*position) && (this->*velocity != other.*velocity))
    {
        return false;
    }
    return true; 
}

double Particle::getW() const
{
    return w;
}

double Particle::getC1() const
{
    return c1;
}

double Particle::getC2() const
{
    return c2;
}

double Particle::getVMax() const
{
    return vMax;
}









