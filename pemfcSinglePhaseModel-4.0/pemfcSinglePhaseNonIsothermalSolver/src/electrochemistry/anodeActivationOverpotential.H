//   calculate for DMFC Maricarmen Duarte
//   eta-anode= (RT/alpha*f)* ln 

//

scalarField etaActivationAnode(anodePatch.size());
{
    // Compute anodic overpotential
    etaActivationAnode = 
    (
        ((Rgas*anodeT)
        /(alphaAnodeElectrolyte.value()*F))
        *Foam::log((I * cMeRef.value())/(i0A * concMe))
    );

    Info<< "min,mean,max (etaActCa) = " << gMin(etaActivationAnode) << "  "
        << gAverage(etaActivationAnode) << "  " << gMax(etaActivationAnode) << nl;
}

//  Save data for output

scalarField& etaAtcAIn = etaActA.ref();
smearPatchToMesh smearetaActA(electrolyteMesh, electrolyteAnodeName);
etaAtcAIn = smearetaActA.smear(etaActivationAnode);
etaActA.correctBoundaryConditions();
etaActA.boundaryFieldRef()[electrolyteAnodeID] == etaActivationAnode;
