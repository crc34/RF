
#include <vector>
#include <iostream>
#include <memory>
#include <numeric>
#include <string>
#include <functional>

using std::shared_ptr;
using std::vector;

const int binomial(const int nSamples, const double successProb)
{
    auto nSuccesses = 0;
    for( int i = 0; i < nSamples; i++)
    {
        auto rnd = ((double) rand() / (RAND_MAX)); 
        if (rnd < successProb)
        {
            nSuccesses++;
        }
    }
    return nSuccesses;
}



shared_ptr<const int> multinomial(shared_ptr<double> weights, const int nWeights, const int nSamples)
{
    shared_ptr<int> samples(new int[nSamples]);
    vector<double> probabilities(weights.get(), weights.get() + nWeights);
    auto start = probabilities.begin();
    auto end = probabilities.end();
    auto remainingSamples = nSamples;
    for (int i = 0; i < nWeights; i++)
    {
        auto total = std::accumulate(start, end, 0);
        auto prob = probabilities[i]/total;
        auto draw =  binomial(remainingSamples, prob);
        samples.get()[i] = draw;
        remainingSamples -= draw;
        start++;
    }
    return samples;
}



