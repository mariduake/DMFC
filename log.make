+ cd lib
+ ./Allwmake
+ wmake libso
g++ -std=c++0x -m64 -Dlinux64 -DWM_ARCH_OPTION=64 -DWM_DP -DWM_LABEL_SIZE=32 -Wall -Wextra -Wold-style-cast -Wnon-virtual-dtor -Wno-unused-parameter -Wno-invalid-offsetof -O3  -DNoRepository -ftemplate-depth-100 -g -I/home/fatima/OpenFOAM/OpenFOAM-4.0/src/finiteVolume/lnInclude -I/home/fatima/OpenFOAM/OpenFOAM-4.0/src/meshTools/lnInclude  -IlnInclude -I. -I/home/fatima/OpenFOAM/OpenFOAM-4.0/src/OpenFOAM/lnInclude -I/home/fatima/OpenFOAM/OpenFOAM-4.0/src/OSspecific/POSIX/lnInclude   -fPIC -c diffusivityModels/fsgDiffusionVolumes/fsgDiffusionVolumes.C -o Make/linux64GccDPInt32Opt/diffusivityModels/fsgDiffusionVolumes/fsgDiffusionVolumes.o
diffusivityModels/fsgDiffusionVolumes/fsgDiffusionVolumes.C:70:1: error: initializer-string for array of chars is too long [-fpermissive]
 };
 ^
/home/fatima/OpenFOAM/OpenFOAM-4.0/wmake/rules/General/transform:8: fallo en las instrucciones para el objetivo 'Make/linux64GccDPInt32Opt/diffusivityModels/fsgDiffusionVolumes/fsgDiffusionVolumes.o'
make: *** [Make/linux64GccDPInt32Opt/diffusivityModels/fsgDiffusionVolumes/fsgDiffusionVolumes.o] Error 1
+ pwd
/home/fatima/OpenFOAM/fatima-4.0/run/pemfcSinglePhaseModel-4.0/pemfcSinglePhaseNonIsothermalSolver
+ cd applications
+ wmake
g++ -std=c++0x -m64 -Dlinux64 -DWM_ARCH_OPTION=64 -DWM_DP -DWM_LABEL_SIZE=32 -Wall -Wextra -Wold-style-cast -Wnon-virtual-dtor -Wno-unused-parameter -Wno-invalid-offsetof -O3  -DNoRepository -ftemplate-depth-100 -g -I../src/constants -I../src/createFields -I../src/createMesh -I../src/createSpecies -I../src/diffusivity -I../src/electrochemistry -I../src/energyTransport -I../src/mapping -I../src/momentumTransport -I../src/multiSpeciesTransport -I../src/patch -I../src/physicalProperties -I../src/readParameters -I../src/readProperties -I../src/tools/functions -I../src/tools/functionIntegration -I../src/tools/ReynoldsNumber -I../src/tools/RiddersRoot -I../src/tools/varInit -I../lib/lnInclude -I/home/fatima/OpenFOAM/OpenFOAM-4.0/src/finiteVolume/lnInclude -I/home/fatima/OpenFOAM/OpenFOAM-4.0/src/meshTools/lnInclude -I/home/fatima/OpenFOAM/OpenFOAM-4.0/src/thermophysicalModels/specie/lnInclude  -IlnInclude -I. -I/home/fatima/OpenFOAM/OpenFOAM-4.0/src/OpenFOAM/lnInclude -I/home/fatima/OpenFOAM/OpenFOAM-4.0/src/OSspecific/POSIX/lnInclude   -fPIC -c pemfcSinglephaseNonIsothermalSolver.C -o Make/linux64GccDPInt32Opt/pemfcSinglephaseNonIsothermalSolver.o
In file included from ../src/electrochemistry/solveElectrochemistry.H:176:0,
                 from pemfcSinglephaseNonIsothermalSolver.C:141:
../src/electrochemistry/totalCurrent.H: In function ‘int main(int, char**)’:
../src/electrochemistry/totalCurrent.H:45:9: error: no matching function for call to ‘functionTotalCurrent::functionTotalCurrent(double&, double&, double&, Foam::scalar&, double&, Foam::scalar&, double&, Foam::dimensionedScalar&, double&, Foam::dimensionedScalar&, double&)’
         );
         ^
In file included from pemfcSinglephaseNonIsothermalSolver.C:56:0:
../src/tools/functions/functionTotalCurrent.H:8:5: note: candidate: functionTotalCurrent::functionTotalCurrent(Foam::scalar, Foam::scalar, Foam::scalar, Foam::scalar, Foam::scalar, Foam::scalar, Foam::scalar, Foam::scalar, Foam::scalar, Foam::scalar, Foam::scalar)
     functionTotalCurrent(scalar Nernst, scalar Vcell, scalar R, scalar A, scalar i0C, scalar B, scalar i0A, 
     ^
../src/tools/functions/functionTotalCurrent.H:8:5: note:   no known conversion for argument 8 from ‘Foam::dimensionedScalar {aka Foam::dimensioned<double>}’ to ‘Foam::scalar {aka double}’
../src/tools/functions/functionTotalCurrent.H:1:7: note: candidate: constexpr functionTotalCurrent::functionTotalCurrent(const functionTotalCurrent&)
 class functionTotalCurrent
       ^
../src/tools/functions/functionTotalCurrent.H:1:7: note:   candidate expects 1 argument, 11 provided
../src/tools/functions/functionTotalCurrent.H:1:7: note: candidate: constexpr functionTotalCurrent::functionTotalCurrent(functionTotalCurrent&&)
../src/tools/functions/functionTotalCurrent.H:1:7: note:   candidate expects 1 argument, 11 provided
/home/fatima/OpenFOAM/OpenFOAM-4.0/wmake/rules/General/transform:8: fallo en las instrucciones para el objetivo 'Make/linux64GccDPInt32Opt/pemfcSinglephaseNonIsothermalSolver.o'
make: *** [Make/linux64GccDPInt32Opt/pemfcSinglephaseNonIsothermalSolver.o] Error 1
