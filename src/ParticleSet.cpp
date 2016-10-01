
#include "ParticleSet.h"
using std::memcpy;

particleSet::particleSet(const int nParticles,
    const int stateSpaceDimension,
    const int auxStateSpaceDimension) :
    nParticles(nParticles),
    stateSpaceDimension(stateSpaceDimension),
    auxStateSpaceDimension(auxStateSpaceDimension),
    m_weights(new double[nParticles]),
    m_particles(new double[nParticles]),
    m_parentIndex(new int[nParticles]) 
{        
}

particleSet::particleSet(const particleSet& obj) :
    nParticles(obj.nParticles),
    stateSpaceDimension(obj.stateSpaceDimension),
    auxStateSpaceDimension(obj.auxStateSpaceDimension),
    m_weights(new double[nParticles]),
    m_particles(new double[nParticles]),
    m_parentIndex(new int[nParticles]) 
{
    memcpy(m_weights.get(), obj.m_weights.get(), sizeof(m_weights.get()));
    memcpy(m_particles.get(), obj.m_particles.get(), sizeof(m_particles.get()));
    memcpy(m_parentIndex.get(), obj.m_parentIndex.get(), sizeof(m_parentIndex.get()));
}

bool particleSet::operator==(const particleSet& other)
{
    bool equal = true;
    equal &= (nParticles == other.nParticles);
    equal &= (stateSpaceDimension == other.stateSpaceDimension);
    equal &= (auxStateSpaceDimension == other.auxStateSpaceDimension);
    // Intentionally testing for equality of floating point values. This function is
    // for testing the copy constructor.
    equal &= memcmp(m_weights.get(), other.m_weights.get(), sizeof(m_particles.get())) == 0;
    equal &= memcmp(m_particles.get(), other.m_particles.get(), sizeof(m_particles.get())) == 0;
    equal &= memcmp(m_parentIndex.get(), other.m_parentIndex.get(), sizeof(m_parentIndex.get())) == 0;
    return equal;
}

bool particleSet::operator!=(const particleSet& other)
{
    return !(*this ==(other));
}

