#include "PSO.h"

PSO::PSO(string fileName)
{
    particles = NULL; numParticles = 0;

    std::ifstream file(fileName);
    std::string line;
    
    while (std::getline(file,line))
    {
        ++numParticles;
    }

    particles = new Particle*[numParticles];
    file.clear();
    file.seekg(0,std::ios::beg); 


    for (int k = 0; k < numParticles; k++)
    {  
        std::getline(file,line);
        particles[k] = line;
    }
    file.close();
}

PSO::~PSO()
{
     delete[] particles;
}

const Particle& PSO::run(const Function& func)
{
     Particle* gBest = particles[0];

     for (int s = 0; s < numParticles; ++s)
     {
        if (func(particles[s]) < func(gBest))
        gBest = particles[i];  
     }

     for (int s = 0; s < numParticles;++s)
     {
       particles[i]->updateParticle(*gBest);
     }
       return *gBest;

}

Particle** PSO::run(int numIterations, const Function& func)
{
    Paricle** bestParticles = new Particle*[numIterations];

    for (int s = 0; s < numIterations; ++s)
    {
        const Particle& best = run(func);
        bestParticle[s] = new Particle(best);
    }
    return bestParticles;
}

Particle* PSO::getBestParticle(const Function& func) const
{
    Particle* Best = particles[0];

    for (int s = 0; func(Best) < func(particles[s]))
    {
        Best = particles[s]; 
    }
}

Particle** PSO::getParticels() const
{
   return particles;
}

int PSO::getNumberOfParticles() const
{
   return numParticals;
}

Particle* PSO::getParticle(int pos) const
{
    if (pos < 0 || pos > numParticles)
    {
        return NULL;
    }

    return particles[pos]; 
}

Particle* PSO::getParticle(const Vector& position) const 
{
    for (int s = 0; s < numParticles; s++)
    {
        if (particles[s]->getPosition() == position)
        {
            return particles[s];
        }
    }
    return = NULL;
}

int PSO::addParticle(const Particle& nParticle)
{
    Particle** newParticles = new Particle*[numParticles + 1];

    for (int s = 0; s < numParticels; s++ )
    {
        newParticles[s] = particels[s];
    }

    newParticle[numParticles] = new Particels(nParticle);
    delete[] particels;
    particels = newParticels;
    numParticels++;

    return (numParticles-1); 
}

bool PSO::removeParticle(const Particle& particle)
{
   bool bFound = false;

   for (int s = 0; s < numParticels; s++)
   {
     if (particles[s]->equal(particle))
     {
        delete particels[s];

        for (int m = 0; m < numParticels-1;++m)
        particels[m] = particels[m+1];
        bFound = true;
        numParticles -= 1;       
     }
     else{return false;}
   } 

   if (bFound = true)
   {
    Particle** newParticels[numParticels] = new Particel*[numParticels];
    for (int s =0;s<numParticles;s++)
    newParticels[s]=particels[s];

    delete[] particels;
    particels = newParticles;
   }
   return found;
}

bool PSO::removeParticle(const Vector& position)
{
    for (int s=0;s< =numParticles;s++)
    {
        if (particels[s]->getPosition() ==position)
        return removeParticle(*particels[s]);
    }
    return (false);
}

bool PSO::removeParticle(int pos) 
{
    if ((pos<0) || (pos >=numParticles))
    return (false);

    return (true);
}
