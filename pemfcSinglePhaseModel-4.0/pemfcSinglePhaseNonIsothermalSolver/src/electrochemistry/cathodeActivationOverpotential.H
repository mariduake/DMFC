//    Calculating cathode activation overpotential 
//   calculate for DMFC Maricarmen Duarte
//   eta-cathode= (RT/alpha*f)* ln (I*cO2Ref/I0C*concO2)
//


scalarField etaActivationCathode(cathodePatch.size());
{
    // Compute cathodic overpotential
    etaActivationCathode = 
    (
        ((Rgas*cathodeT)
        /(alphaCathodeElectrolyte.value()*F))
        *Foam::log(I * cO2Ref.value()/i0C * concO2)
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
