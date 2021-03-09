// Code changed and adapted to pemfc (J.P.Kone, 22.11.2016)
// for coversion to openfoam-4.0
// call to 'internalField()' is changed to 'ref()'

{
    // anode bipolar plate
    {
        forAll (TanodeBP, cellI)
        {
            TanodeBP[cellI] = Tcell[abpCellMap[cellI]];
        }
        TanodeBP.correctBoundaryConditions();
    }

    // Fuel
    {
        forAll (Tfuel, cellI)
        {
            Tfuel[cellI] = Tcell[fuelCellMap[cellI]];
        }
        Tfuel.correctBoundaryConditions();
    }

    // electrolyte
    {
        forAll (Telectrolyte, cellI)
        {
            Telectrolyte[cellI] = Tcell[electrolyteCellMap[cellI]];
        }
        Telectrolyte.correctBoundaryConditions();
    }

    // Air
    {
        forAll (Tair, cellI)
        {
            Tair[cellI] = Tcell[airCellMap[cellI]];
        }
        Tair.correctBoundaryConditions();
    }


    // cathode bipolar plate
    {
        forAll (TcathodeBP, cellI)
        {
            TcathodeBP[cellI] = Tcell[cbpCellMap[cellI]];
        }
        TcathodeBP.correctBoundaryConditions();
    }


    Info << "Tfuel min mean max = "
         << Foam::gMin(Tfuel.ref())     << "    "
         << Foam::gAverage(Tfuel.ref()) << "    "
         << Foam::gMax(Tfuel.ref())
         << endl;

    Info << "Tair min mean max  = "
         << Foam::gMin(Tair.ref())     << "    "
         << Foam::gAverage(Tair.ref()) << "    "
         << Foam::gMax(Tair.ref())
         << endl;
}

