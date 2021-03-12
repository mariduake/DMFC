class functionTotalCurrent
{
    scalar Nernst_, Vcell_, R_, A_, i0C_, B_, i0A_, cO2Ref_, cMeRef_, concO2_, concMe_ ;

    
public: 

    functionTotalCurrent(scalar Nernst, scalar Vcell, scalar R, scalar A, scalar i0C, scalar B, scalar i0A, 
                         scalar CO2Ref, scalar cMeRef, scalar concO2, scalar concMe)
    :
    Nernst_(Nernst),
    Vcell_(Vcell),
    R_(R),
    A_(A),
    i0C_(i0C),
    B_(B),
    i0Anode_(i0A),
    cO2Ref_(cO2Ref),
    cMeRef_(cMeRef),
    concO2_(concO2),
    concMe_(concMe)
    {}

    scalar operator()(const scalar& i) const
    {
        return Nernst_-(i*R_)-(A_*Foam::log(i*cO2Ref_/i0Cathode_*conO2_))-Vcell_-(B_*Foam::log(i*cMeRef_/(i0Anode_*concMe)));
    }
};

//MODIFIED FUNCTION TO ADAPT IT TO A DMFC 
// MARICARMEN DUARTE AKE 2021
// cO2Ref, cMeRef /run/constant/cellProperties


