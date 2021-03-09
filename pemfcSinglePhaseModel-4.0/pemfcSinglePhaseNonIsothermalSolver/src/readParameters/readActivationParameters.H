// Code changed and adapted to pemfc electrochemistry (J.P.Kone, 17.10.2016)

    Info<< "Reading activation parameters\n" << endl;

    IOdictionary activationParameters
    (
        IOobject
        (
            "activationParameters",
            runTime.constant(),
            electrolyteMesh,
            IOobject::MUST_READ,
            IOobject::NO_WRITE
        )
    );

    // Read electrode kinetic parameters
    //anode ADDED MARICARMEN DUARTE
    dimensionedScalar i0AnodeElectrolyteReference(activationParameters.lookup("i0aReference"));
    dimensionedScalar EAnodeElectrolyte(activationParameters.lookup("EAnode"));
    dimensionedScalar alphaAnodeElectrolyte(activationParameters.lookup("alphaAnode"));
    // cathode
    dimensionedScalar i0CathodeElectrolyteReference(activationParameters.lookup("i0Reference"));
    dimensionedScalar ECathodeElectrolyte(activationParameters.lookup("ECathode"));
    dimensionedScalar alphaCathodeElectrolyte(activationParameters.lookup("alphaCathode"));

    // echo inputs from dictionary to stdout
    Info
    //ADDED INFO MARICARMEN DUARTE 
        << "    i0AnodeElectrolyteReference    = " << i0AnodeElectrolyteReference << nl
        << "    EAnodeElectrolyte    = " << EAnodeElectrolyte << nl
        << "    alphaAnodeElectrolyte    = " << alphaAnodeElectrolyte << nl
    //REGULAR INPUT
        << "    i0CathodeElectrolyteReference    = " << i0CathodeElectrolyteReference << nl
        << "    ECathodeElectrolyte    = " << ECathodeElectrolyte << nl
        << "    alphaCathodeElectrolyte    = " << alphaCathodeElectrolyte << nl
        << endl;
