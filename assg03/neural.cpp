#include<vector>


struct SNeuron{
    // no of inputs to Neuuron
    int m_NumInputs;

    // the weights fro each input
    vector<double> m_vecWeight;

    SNeuron(int NumInputs);
};

SNeuron::SNeuron(int NumInputs): m_NumInputs(NumInputs + 1)
{
    for(int i=0; i <NumInputs +1 ; ++i)
    {
        // set the weights at intiial to random
        m_vecWeight.push_back(RandomClamped());


    }

}
