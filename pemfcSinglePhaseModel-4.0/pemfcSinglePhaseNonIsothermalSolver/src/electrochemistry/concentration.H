// calculating concentrarions (CH3OH & O2){Maricarmen Duarte aké}
//    Conc_k =Y_k*rho_k/M_k
//              
//    where
//    y_k = mass fraction of k
//    rho_k = density of air
//    M_k = molecular weight of k


scalarField concentrationO2(cathodePatch.size());
{
         //Compute O2 concentration

   forAll(airSpecies, s)
   {
      if (airSpecies[s].rSign() == -1)
      {
           concentrationO2 =
           (  
                 (Yair[s].boundaryFieldRef()[cathodeID]
                  *rhoAir.boundaryFieldRef()[cathodeID])
                  /(airSpecies[s].MW())
                );
                concentrationO2 *=1.0e+3;
       }
    }
    Info << "min,mean,max(concentrationO2)= " <<gMin(concentrationO2)<< "  "
         << gAverage(concentrationO2) << "  " << gMax(concentrationO2) <<nl;
}

//Save data for output
scalarField& concO2In=concO2.ref();
smearPatchToMesh smearconcO2(electrolyteMesh, electrolyteCathodeName);
concO2In = smearconcO2.smear(concentrationO2);
concO2.correctBoundaryConditions();
concO2.boundaryFieldRef()[electrolyteCathodeID] ==concentrationO2;

scalarField concentrationMe(anodePatch.size());
{
         //Compute CH3OH/Methanol concentration

   forAll(fuelSpecies, s)
   {
      if (airSpecies[s].rSign() == -1)
      {
           concentrationMe =
           (  
                 (Yfuel[s].boundaryFieldRef()[anodeID]
                  *rhoFuel.boundaryFieldRef()[anodeID])
                  /(fuelSpecies[s].MW())
                );
                concentrationMe *=1.0e+3;
       }
    }
    Info << "min,mean,max(concentrationMe)= " <<gMin(concentrationMe)<< "  "
         << gAverage(concentrationMe) << "  " << gMax(concentrationMe) <<nl;
}

//Save data for output
scalarField& concMeIn=concMe.ref();
smearPatchToMesh smearconcMe(electrolyteMesh, electrolyteAnodeName);
concMeIn = smearconcMe.smear(concentrationMe);
concMe.correctBoundaryConditions();
concMe.boundaryFieldRef()[electrolyteAnodeID] ==concentrationMe;
