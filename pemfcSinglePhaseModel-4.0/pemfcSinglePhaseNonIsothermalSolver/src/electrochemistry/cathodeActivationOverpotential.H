//    Calculating cathode activation overpotential (J.P.Kone, 01.11.2016)
//   calculate for DMFC Maricarmen Duarte
//   eta-anode= (RT/alpha*f)* ln 
//

scalarField etaActivationCathode(cathodePatch.size());
{
    // Compute cathodic overpotential
    etaActivationCathode = 
    (
        ((Rgas*cathodeT)
        /(alphaCathodeElectrolyte.value()*F))
        *Foam::log(I*cO2Ref/i0Cathode*concentrationO2)
    );

    Info<< "min,mean,max (etaActCa) = " << gMin(etaActivationCathode) << "  "
        << gAverage(etaActivationCathode) << "  " << gMax(etaActivationCathode) << nl;
}

//  Save data for output

scalarField& etaAtcCIn = etaActC.ref();
smearPatchToMesh smearetaActC(electrolyteMesh, electrolyteCathodeName);
etaAtcCIn = smearetaActC.smear(etaActivationCathode);
etaActC.correctBoundaryConditions();
etaActC.boundaryFieldRef()[electrolyteCathodeID] == etaActivationCathode;
