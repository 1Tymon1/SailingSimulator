// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class VirtuSphereClient : ModuleRules
{
	public VirtuSphereClient(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		string ThirdPartyDirectory = Path.Combine(PluginDirectory, "ThirdParty");
		string NetHostDirectory = Path.Combine(ThirdPartyDirectory, "nethost");
		string ClientDirectory = Path.Combine(ThirdPartyDirectory, "VirtuSphereClient");
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
				Path.Combine(NetHostDirectory, "include")
            }
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);

		PublicAdditionalLibraries.AddRange(
			new string[]
			{
				Path.Combine(NetHostDirectory, "nethost.lib")
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "Projects",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

		RuntimeDependencies.Add("$(BinaryOutputDir)/nethost.dll", Path.Combine(NetHostDirectory, "nethost.dll"));

        string[] runtimeFiles = Directory.GetFiles(ClientDirectory);
		foreach(string runtimeFile in runtimeFiles)
		{
			RuntimeDependencies.Add(runtimeFile);
        }

    }
}
