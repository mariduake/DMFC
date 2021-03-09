    // Code changed and adapted to pemfc (J.P.Kone, 13.06.2016)

    Info<< "Reading cell properties\n" << endl;

    IOdictionary cellProperties
    (
        IOobject
        (
            "cellProperties",
            runTime.constant(),
            mesh,
            IOobject::MUST_READ,
            IOobject::NO_WRITE
        )
    );

    word fuelCellType(cellProperties.lookup("fuelCellType"));		//Qing, 04.06.2014

    Switch galvanostatic(cellProperties.lookup("galvanostatic"));
    dimensionedScalar V(cellProperties.lookup("voltage"));
    dimensionedScalar Ibar0(cellProperties.lookup("Ibar0"));
    dimensionedScalar Tinit(cellProperties.lookup("Tinit"));
    dimensionedScalar numCells(cellProperties.lookup("numCells"));
    dimensionedScalar Rhat("Rhat", dimensionSet(1, 4, -3, 0, 0, -2, 0), 0);
    dimensionedScalar Rhat0("Rhat0", dimensionSet(1, 4, -3, 0, 0, -2, 0), 0);	//Qing, 22.06.2014
    dimensionedScalar kappaCl(cellProperties.lookup("kappaCl"));
    dimensionedScalar kappaGdl(cellProperties.lookup("kappaGdl"));
    dimensionedScalar rContact(cellProperties.lookup("rContact"));
    dimensionedScalar kappaBp(cellProperties.lookup("kappaBp"));
    dimensionedScalar tCl(cellProperties.lookup("tCl"));
    dimensionedScalar tGdl(cellProperties.lookup("tGdl"));
    dimensionedScalar tBp(cellProperties.lookup("tBp"));
    dimensionedScalar epsilonGdl(cellProperties.lookup("epsilonGdl"));
    dimensionedScalar epsilonCl(cellProperties.lookup("epsilonCl"));
    dimensionedScalar etaConCaConstant(cellProperties.lookup("etaConCaConstant"));
    dimensionedScalar cMeRef(cellProperties.lookup("cMeRef"));
    dimensionedScalar cO2Ref(cellProperties.lookup("cO2Ref"));


    // echo inputs from dictionary to stdout
    // -------------------------------------
    if (galvanostatic)
    {
        Info<< "galvanostatic run" << nl;
        Info<< "    V     = " << V << nl;
        Info<< "    Ibar0 = " << Ibar0 << nl;

        Rhat = cellProperties.lookup("Rhat");
        Info<< "    Rhat  = " << Rhat << nl;

        Rhat0 = cellProperties.lookup("Rhat0");
	Info<< "    Rhat0  = " << Rhat0 << nl;
    }
    else
    {
        Info<< "potentiostatic run" << nl;
        Info<< "    Ibar0 = " << Ibar0 << nl;
        Info<< "    V     = " << V << nl;
    }

    Info<< "CL electronic conductivity(kappaCl) = " << kappaCl << nl
        << "GDL electronic conductivity(kappaGdl) = " << kappaGdl << nl
        << "GDL - BP Contact resistance (rContact)= " << rContact << nl
        << "BP electronic conductivity(kappaBp) = " << kappaBp << nl
        << "CL thickness (tCl) = " << tCl << nl
        << "GDL thickness (tGdl) = " << tGdl << nl
        << "BP thickness (tBp) = " << tBp << nl
        << "concentration overpotential constant = " << etaConCaConstant << nl
        << endl;

    Info<< "    Tinit = " << Tinit << nl;
    Info<< endl;


    // special patch names
    // -------------------
    word anodeName(cellProperties.lookup("anodePatch"));
    word fuelInletName(cellProperties.lookup("fuelInletPatch"));
    word fuelOutletName(cellProperties.lookup("fuelOutletPatch"));
    word fuelAbpName(cellProperties.lookup("fuelAbpPatch")); // added (J.P. Kone, 13.06.2016)

    word cathodeName(cellProperties.lookup("cathodePatch"));
    word airInletName(cellProperties.lookup("airInletPatch"));
    word airOutletName(cellProperties.lookup("airOutletPatch"));
    word airCbpName(cellProperties.lookup("airCbpPatch")); // added (J.P. Kone, 13.06.2016)

    word electrolyteAnodeName
        (cellProperties.lookup("electrolyteAnodePatch"));

    word electrolyteCathodeName
        (cellProperties.lookup("electrolyteCathodePatch"));

    word abpFuelName
            (cellProperties.lookup("abpFuelPatch")); // added (J.P. Kone, 13.06.2016)

    word cbpAirName
                (cellProperties.lookup("cbpAirPatch")); // added (J.P. Kone, 13.06.2016)


    // echo inputs from dictionary to stdout
    Info
        << "    anodeName              = " << anodeName << nl
        << "    fuelInletName          = " << fuelInletName << nl
        << "    fuelOutletName         = " << fuelOutletName << nl
	<< "    fuelAbpName            = " << fuelAbpName << nl // added (J.P. Kone, 13.06.2016)
        << "    cathodeName            = " << cathodeName << nl
        << "    airInletName           = " << airInletName << nl
        << "    airOutletName          = " << airOutletName << nl
	<< "    airCbpName             = " << airCbpName << nl // added (J.P. Kone, 13.06.2016)
        << "    electrolyteAnodeName   = " << electrolyteAnodeName << nl
        << "    electrolyteCathodeName = " << electrolyteCathodeName << nl
	<< "    abpFuelName            = " << abpFuelName << nl // added (J.P. Kone, 13.06.2016)
	<< "    cbpAirName             = " << cbpAirName << nl // added (J.P. Kone, 13.06.2016)
        << endl;

