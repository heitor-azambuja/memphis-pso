# Memphis PSO
A very simple c++ implementation of pso algorithm in Memphis, an experimental virtual parallelization platform.

## How to use

First you have to install the Memphis platform by GAPH-PUCRS. [Repository](https://github.com/gaph-pucrs/Memphis/), [Video Tutorial](https://www.youtube.com/watch?v=nvgtvFcCc60&ab_channel=GAPH-PUCRS).

After Memphis installation, follow the steps pelow:

Create pso environment by running the following command:

```
$ memphis-gen pso-environment.yaml
```

Copy the folders parallel-pso and sequential-pso to pso-environment/applications folder in memphis home.

Compine and run sequential or parallel pso running the commands in the repository directory:
```
$ memphis-app pso-environment.yaml -all sequential-pso.yaml
$ memphis-run pso-environment.yaml sequential-pso.yaml 100000
```
substitute the yaml file by the version of pso you wish to run. The third value in the second command is the execution time in ms. Small times will cause the simulation to finish before the pso starts. You can probably get it to work with a smaller time though. For me, 25 ms did not work, 100000 in the second attempt worked and I stuck to it.

To stpo execution just run:
```
$ killall sequential-pso
```

## References
- Memphis Platform ([Repository](https://github.com/gaph-pucrs/Memphis/))
- A Survey on Parallel Particle Swarm Optimization Algorithms ([Article](https://www.researchgate.net/publication/330249950_A_Survey_on_Parallel_Particle_Swarm_Optimization_Algorithms))
- Codes in MATLAB for Particle Swarm Optimization ([Code](https://www.researchgate.net/publication/296636431_Codes_in_MATLAB_for_Particle_Swarm_Optimization))

## Author
- Heitor Teixeira de Azambuja

## License

MIT License

Copyright (c) 2022 Heitor Teixeira de Azambuja

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.