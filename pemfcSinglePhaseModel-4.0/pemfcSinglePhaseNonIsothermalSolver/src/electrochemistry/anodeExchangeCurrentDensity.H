// calculating anode exchange current density (MARICARMEN DUARTE 2021)

//    For anode (fuel)
//    i0Anode = i0,ref(353.15)*exp[-EAct/(R)*(1/T-1/353.15)]
//    where
//    io(353.15) = reference exchange current density at 353.15K
//    EAct = Activation energy
//    R = gas constant
//    T = anode temperature
//

scalarField i0Anode(anodePatch.size());
{
    // Compute local cathode exchange current density
    i0Anode = 
    (
        i0AnodeElectrolyteReference.value()
        *Foam::exp(((-1.*EAnodeElectrolyte.value())/(Rgas))
        *((1.0/anodeT)-(1.0/353.15)))
    );

    Info<< "min,mean,max (anodeT) = " << gMin(anodeT) << "  "
        << gAverage(anodeT) << "  " << gMax(anodeT) << nl;
    Info<< "min,mean,max (i0An) = " << gMin(i0Anode) << "  "
        << gAverage(i0Anode) << "  " << gMax(i0Anode) << nl;
}

//  Save data for output (J.P.Kone, 05.07.2017)
/*scalarField& i0CIn = i0C.ref();
smearPatchToMesh smeari0C(electrolyteMesh, electrolyteCathodeName);
i0CIn = smeari0C.smear(i0Cathode);
i0C.correctBoundaryConditions();
i0C.boundaryFieldRef()[electrolyteCathodeID] == i0Cathode;*/

//save data for output (MARICARMEN DUARTE 2021)
scalarField& i0AIn = i0A.ref();
smearPatchToMesh smeari0A(electrolyteMesh, electrolyteAnodeName);
i0AIn = smeari0A.smear(i0Anode);
i0A.correctBoundaryConditions();
i0A.boundaryFieldRef()[electrolyteAnodeID] == i0Anode;
