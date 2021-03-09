################################################################################
All: mesh parprep run reconstruct view
mesh: bmesh patchBC regionSets regionInterface regionMesh control
###############
clean:
	(rm -rf *.log [1-9]*);
clear:
	(./Allclean)
###############
bmesh:
	(cp -rf ./system/controlDict.mesh ./system/controlDict);
	(blockMesh);
patchBC:
	(rm -rf ./constant/polyMesh/sets);
	(topoSet -dict ./config/faceSets.topoSetDict);
	(rm -rf ./constant/polyMesh/sets/*_old);
	(topoSet -dict ./config/faceSetsAir.topoSetDict);
	(rm -rf ./constant/polyMesh/sets/*_old);
	(topoSet -dict ./config/faceSetsFuel.topoSetDict);
	(rm -rf ./constant/polyMesh/sets/*_old);
	(setsToZones -noFlipMap);
	(createPatch -overwrite);
regionSets:
	(rm -rf constant/polyMesh/sets constant/polyMesh/*Zones);
	(topoSet -dict ./config/cellSets.topoSetDict);
	(rm -rf constant/polyMesh/sets/*_old);
	(setsToZones -noFlipMap);
regionInterface:
	(topoSet -dict ./config/faceSetsIFaces.topoSetDict);
	(rm -rf constant/polyMesh/sets/*_old);
	(rm constant/polyMesh/sets/[abc]Faces);
	(setsToZones -noFlipMap);
regionMesh:
	(splitMeshRegions -cellZonesOnly);
	(cp -r 0.001/* ./constant);
	(rm -rf 0.001);
	(topoSet -region air -dict config/cellSetsAir.topoSetDict);
	(setsToZones -noFlipMap -region air);
	(topoSet -region electrolyte -dict config/cellSetsElectrolyte.topoSetDict);
	(setsToZones -noFlipMap -region electrolyte);
	(topoSet -region fuel -dict config/cellSetsFuel.topoSetDict);
	(setsToZones -noFlipMap -region fuel);		
	(rm -f constant/[aacef]*/[kpTU] constant/[aacef]*/rho);
	(rm -f constant/[aacef]*/Y* constant/[aacef]*/diff*);
control:
	(cp -rf ./system/controlDict.run ./system/controlDict);
#############
parprep:
	(./parprep.csh | tee log.parprep);
#############
run:
	( pemfcSinglephaseNonIsothermalSolver | tee log.run );
	
###(./prun | tee log.prun);
srun:
	(pemfcSinglephaseNonIsothermalSolver | tee log.srun);
#############
reconstruct:
	(reconstructPar);
	(reconstructPar -region cbp);
	(reconstructPar -region air);
	(reconstructPar -region electrolyte);
	(reconstructPar -region fuel);
	(reconstructPar -region abp);
#############
view:
	(foamToVTK -ascii -latestTime);
	(foamToVTK -ascii -latestTime -region cbp);
	(foamToVTK -ascii -latestTime -region air);
	(foamToVTK -ascii -latestTime -region electrolyte);
	(foamToVTK -ascii -latestTime -region fuel);
	(foamToVTK -ascii -latestTime -region abp);
viewAll:
	(foamToVTK -ascii);
	(foamToVTK -ascii -region cbp);
	(foamToVTK -ascii -region air);
	(foamToVTK -ascii -region electrolyte);
	(foamToVTK -ascii -region fuel);
	(foamToVTK -ascii -region abp);
################################################################################
