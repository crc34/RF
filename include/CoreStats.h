#include <memory>
using std::shared_ptr;

const int binomial(const int nSamples, const double failureProb);

shared_ptr<const int> multinomial(shared_ptr<double> weights,
    const int nWeights, const int nSamples);
