{
    // integrate heat flux over all patches
    // ------------------------------------
    
    scalar qVect = 0;      //patch integral of convective flux
    scalar qVectSum = 0;   //accumulator over all patches

    scalar qDuct = 0;      //patch integral of conductive flux
    scalar qDuctSum = 0;   //accumulator over all patches
    
    const polyPatchList& patches = mesh.boundaryMesh();
    
    // boundaryField changed to boundaryFieldRef (J. P. Kone, 23.09.2016)
    forAll(patches, patchI)
    {
        // Int(rho U Cp T & dA)
        qVect = gSum
	(
	    rhoCpPhiCell.boundaryFieldRef()[patchI]
	    *Tcell.boundaryFieldRef()[patchI]
	);
        qVectSum += qVect;

        // Int(k gradT $ dA)
        qDuct = gSum
        (
            kCell.boundaryFieldRef()[patchI]
            *Tcell.boundaryFieldRef()[patchI].snGrad()
            *mesh.magSf().boundaryFieldRef()[patchI]
        );
        qDuctSum += qDuct;
        
        if((qVect != 0) || (qDuct != 0))    //report non-zero values
        {
            Info<< patches[patchI].name()
                << " sum(rhoCpPhiT) = " << qVect
                << "    sum(kGradTdA) = " << qDuct
                << nl;
        }
    }
    Info<< "qVectSum = " << qVectSum 
        << "    qDuctSum = " << qDuctSum
        << nl << endl;


    // electrolyte heating
    // -------------------
    // internalField changed to ref (J. P. Kone, 23.09.2016)
    scalar qSrcSum = gSum
    (
        TsourceCell.ref()*mesh.V()
    );
    Info<< " sum(TsourceCell dV) = " << qSrcSum << nl << endl;


    // Heat transfer from gases to solids (solid component temperature gain)
    // ----------------------------------

}

