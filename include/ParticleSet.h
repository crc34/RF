#pragma once
#include <stdio.h>
#include <string>
#include <functional>
#include <cstring>
#include <memory>
using std::function;
using std::string;
using std::unique_ptr;

class particleSet
{
    public:
        particleSet(const int nParticles,
            const int stateSpaceDimension,
            const int auxStateSpaceDimension);
        particleSet(const particleSet& obj);
        bool operator==(const particleSet& other);
        bool operator!=(const particleSet& other);
        const int nParticles; // number of particles.
        const int stateSpaceDimension; // the dimension of the state space.
        const int auxStateSpaceDimension; // the dimension of the state space.
        const unique_ptr<double> m_weights; // weight of the particles.
        // row-wise matrix of values. Each row is an element of the state-space.
        const unique_ptr<double> m_particles; 
        const unique_ptr<int> m_parentIndex; 
    private:
        particleSet() = delete;
};

