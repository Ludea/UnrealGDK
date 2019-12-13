<%(TOC max="3")%>

# The Starter Template
## 3.  Launch a cloud deployment

Before launching a cloud deployment, as well as generating schema and a snapshot, you also need to:

* Associate your game with its SpatialOS cloud project name.
* Prepare the game’s server-workers and client-workers by building workers.
* Upload the built-out worker assemblies to the cloud.

[block:html]
{
  "html": "<button class=\"collapsible\">Built-out workers - what does it mean?</button><div>\n\n\n\n\n\nYou prepare both your server-workers and client-workers for upload to the cloud by building their assemblies from the code in their `.uproject` files. We call this “building workers”, and the resulting assemblies "built workers".\n\n\n\n</div>"
}
[/block]



**Schema and snapshot**</br>
As you already generated schema and a snapshot for the Example Project when you launched a local deployment, and haven’t changed the project since, you don’t need to generate a schema or snapshot. However, when you do make any changes to the project, you must generate schema and create a snapshot before launching a local or cloud deployment. 

**Hosting cost**</br>
Everyone who signs up for SpatialOS automatically has free cloud deployment hosting via the free tier, so you can use free tier hosting for this Starter Template.


<button class=\"collapsible\">What is the free tier?</button>
<div>


The free tier is ideal for starting development, prototyping a game, conducting technical evaluation, or just learning how to use SpatialOS. It gives you the ability to run one cloud deployment at any time using a specified game template. With the free tier you can also use SpatialOS on your local machine, and we offer free support via the forums.

All the hosting options are available as game templates. For information about which game templates you can use on the free tier, and what they provide, see [Pricing details](<https://docs.improbable.io/reference/latest/shared/pricing-and-support/pricing-intro).


</div>

### Step 1: Associate your game with a SpatialOS cloud project

When you signed up for SpatialOS, your account was automatically associated with an organisation and a SpatialOS cloud project, both of which have the same generated name. You need to associate your game project (your version of the Unreal Starter Template project) with this SpatialOS cloud project name.

> **Tip:** If you have already associated a game project with this SpatialOS cloud project name, you can associate the Unreal Starter Template project with it too. The cloud project can have different game projects associated with it.

1. Find the cloud project by going to the [Console](https://console.improbable.io).</br>
The name should look something like `beta_randomword_anotherword_randomnumber`. In the example below, it’s `beta_yankee_hawaii_621`.</br></br>
![Toolbar]({{assetRoot}}assets/set-up-template/template-project-page.png)<br/>
_Image: The SpatialOS Console with a cloud project name highlighted._
</br></br>
<button class=\"collapsible\">What is the Console?</button>
<div>


The Console is a web-based tool for managing cloud deployments. It gives you access to information about your games’ SpatialOS project names, the SpatialOS assemblies you have uploaded, the internal state of any games you have running (via the Inspector), as well as logs and metrics. </br>You can find out more about the Console in the [Glossary]({{urlRoot}}/content/glossary#console).


</div>

2. In File Explorer, navigate to the `<YourProject>/spatial` directory and open the `spatialos.json` file in a text editor of your choice.
3. In the file, locate the `name` field at the top - it defaults to `demo`. Replace `demo` with the SpatialOS cloud project name shown in the Console (`beta_yankee_hawaii_621` using the example above). This associates your Unreal game with your SpatialOS cloud project, telling SpatialOS which cloud project you are uploading your built-out worker assemblies to.

**Note:** Ensure you only change the `name` field at the top of the file. If you change any other settings, the deployment could fail.

### Step 2: Build workers

> **Note:** Make sure you close your Unreal Editor before you build workers. If the Editor is open when you try to build workers, the command fails.

There are two ways to build workers, and you can choose which one to use. You need to build both server-workers and client-workers.  

- **Build workers automatically using the `BuildProject.bat` script with no flags** </br></br>
  When you use this script with no flags, it automatically builds both the server-workers and client-workers to run your game in the cloud. It then compresses your workers and saves them as .zip files to the `<ProjectRoot>\spatial\build\assembly\worker` directory, ready to upload. Use the script with no flags if you want to build server-workers and client-workers at the same time.<br/></br>
  To do this: </br>
   1. Close your Unreal Editor - if the Editor is open when you try to build workers, the command fails.
   2. In File Explorer, navigate to the `<ProjectRoot>` directory.
   3. Double-click `BuildProject.bat`. </br>
   This opens a command line window and automatically builds your client-workers and server-workers. </br></br>
Problems building workers? See the [Troubleshooting](#troubleshooting) guide below.
    </br></br>
- **Build workers manually using the command line - with optional flags** </br></br>
  Run the `BuildProject.bat` script with added flags from the command line when you want to build your server-workers and client-workers separately,  or, if you want to build different worker configurations. </br>
  <button class=\"collapsible\">What flags are there?</button>
<div>

During development, you might want to, for example:</br> * cook a headless standalone version of the game ready for upload to the SpatialOS cloud as a simulated player cloud deployment, or </br> * cook a stand-alone version of the game to test it as a game client.</br> The optional flags give you this functionality and more.</br></br> See the [Helper script]({{urlRoot}}/content/apis-and-helper-scripts/helper-scripts) documentation for details of all the options and how to use them.
 

</div>
For now, you need to build server-workers and client-workers, so if you haven't run `BuildProject.bat` from File Explorer you need to:</br>
  1. Close your Unreal Editor - if the Editor is open when you try to build workers, the command fails.
  1. Open a terminal window and navigate to the `<ProjectRoot>` directory.
  1. Run the `BuildProject.bat` command to build a server-worker using the filepath and flags below. </br>
  The filepath you use depends on whether you have the `UnrealGDK` plugin set up as an *engine* plugin or as a *project* plugin. If you followed the default setup instructions which use the `InstallGDK.bat` script, you have it set up as an *engine* plugin. <br/></br>
      * Engine plugin filepath (default):</br>
      [block:code]
{
  "codes": [
  {
      "code": "      UnrealEngine\\Engine\\Plugins\\UnrealGDK\\SpatialGDK\\Build\\Scripts\\BuildWorker.bat <YourProject>Server Linux Development <YourProject>.uproject\n",
      "language": "text"
    }
  ]
}
[/block]
      </br>
      * Project plugin filepath:</br>
      [block:code]
{
  "codes": [
  {
      "code": "      <YourProject>\\Game\\Plugins\\UnrealGDK\\SpatialGDK\\Build\\Scripts\\BuildWorker.bat <YourProject>Server Linux Development <YourProject>.uproject",
      "language": "text"
    }
  ]
}
[/block]
      </br></br>
  1. Now run the `BuildProject.bat` command to build a client-worker: <br/><br/>
      * Engine plugin filepath (default):</br>
      [block:code]
{
  "codes": [
  {
      "code": "UnrealEngine\\Engine\\Plugins\\UnrealGDK\\SpatialGDK\\Build\\Scripts\\BuildWorker.bat <YourProject> Win64 Development <YourProject>.uproject",
      "language": "text"
    }
  ]
}
[/block]
      <br/>
      * Project plugin filepath:</br>
      [block:code]
{
  "codes": [
  {
      "code": "<YourProject>\\Game\\Plugins\\UnrealGDK\\SpatialGDK\\Build\\Scripts\\BuildWorker.bat <YourProject> Win64 Development <YourProject>.uproject",
      "language": "text"
    }
  ]
}
[/block]
      <br/><br/>

Whichever way you built workers, you now have one (or two) built-out worker assemblies as `.zip` files in your `<ProjectRoot>\spatial\build\assembly\worker\` directory. `BuildProject.bat` creates one `.zip` file in this directory every time you run it.


#### Troubleshooting
Problems with building workers?</br>
<button class=\"collapsible\">Have you changed the Spatial networking switch?</button>
<div>

You might need to reset the Spatial networking checkbox.</br>  
By default, Spatial networking is enabled for GDK projects, including the Example Project, and we checked it in an [earlier step]({{urlRoot}}/content/get-started/example-project/exampleproject-local-deployment#step-2-launch-and-play) in this guide. However, if you have changed the networking option for this project, you need to reset it to Spatial networking before you build workers.</br></br>
In addition to this guide, there is information on the switch in reference documentation on the [toolbars]({{urlRoot}}/content/unreal-editor-interface/toolbars##switching-between-native-unreal-networking-and-spatialos-networking) switch.</br></br>
**Tip:** In addition to using the Editor to see and change which networking option your project is using, you can look in its `DefaultGame.ini` configuration file (located in the `<ProjectRoot>\Game\Config` directory: </br> * If there is a `bSpatialNetworking` option in the file, set it to `True` to enable Spatial networking. </br> * If there is no `SpatialNetworking` option, you do not have to do anything, as the project will default to using Spatial networking. </br></br>


</div>

<button class=\"collapsible\">BuildProject.bat can’t find the filepath specified.</button>
<div>

If you receive the error `The system cannot find the path specified. Builds failed.` you need to update its filepaths. </br>
To do this: </br>* Open `ProjectPaths.bat` in a text editor. </br> * Ensure that the aliases `PROJECT_PATH` and `GAME_NAME` are correct.</br> </br> 
**Note:** The project filepath depends on whether you followed auto-install or manual-install when you set up the GDK's fork and plugin. </br>
</br>* `PROJECT_PATH` needs to be the name of your Unreal project folder (either `Game` (for auto-install) or `Plugins` (for manual-install) . </br>
* `GAME_NAME` needs to be the same name as your Unreal Project `.uproject` file.  

</div>

### Step 3: Upload built-out workers

Now you can upload your built-out sever-worker and client-workers' assembly `.zip` file(s) to the cloud. </br>
When you do this, you also create an assembly name for the `.zip` file(s) that you upload. In this example, we are using `myassembly` but you can use any name you like with alpha-numberic characters.</br> 
The assembly name is how you identify the group of `.zip` files in this upload on the SpatialOS cloud servers.</br>
To do this: 

1. In a terminal window, navigate to your `<ProjectRoot>\spatial\` directory. 
1. Run the following command: </br>
 `spatial cloud upload myassembly` 
 </br></br>(Remember to replace `myassembly` with a name for your assembly - for example: `mygdktemplateassembly1`). </br></br>
 The upload command looks like this:</br>
[block:code]
{
  "codes": [
  {
      "code": "spatial cloud upload mygdktemplateassembly1",
      "language": "text"
    }
  ]
}
[/block] 
</br>

#### Troubleshooting
Problems with uploading workers?</br>
<button class=\"collapsible\">No upload progress</button>
<div>

* Uploading may be taking a long time due to your connection speed. </br> As the full upload size is around ~800 MB, this step can take a long time on slower connections (that is: slower than 5 Mbps). </br> 
* The progress bar does not always show gradual increments. </br> There is a known issue with the uploader where progress does not change during upload of large files. You'll notice a big jump as it completes uploads of large files.

</div>

### Step 4: Launch your cloud deployment 

The next step is to launch a cloud deployment using the assembly that you just uploaded. You can do this in Unreal Editor or using the SpatialOS CLI's commands. This guide uses Unreal Editor.</br></br>
As part of this step, you can choose to launch some simulated players with your deployment. Simulated players are game clients mimicking real players of your game. You can use them for testing client connection flow and server-worker load at scale.

> **Tip:** You can use the CLI's commands individually from the command line or use them for continuous integration by setting up automated commands to build workers and launch cloud deployments. 

<button class=\"collapsible\">How do I use the SpatialOS CLI?</button>
<div>

The SpatialOS CLI has a set of commands for managing and developing SpatialOS projects. You installed the CLI when you installed SpatialOS as part of _Get Started: 1 - Get the dependencies_. </br> </br>
For more information on the CLI commands for building workers and launching cloud deployments:</br> * See the
[Cloud deployment workflow summary]({{urlRoot}}/content/cloud-deployment-workflow).</br>
* See also the [Glossary]({{urlRoot}}/content/glossary#spatialos-command-line-tool-cli).

</div>

To launch a cloud deployment from Unreal Editor:

1. On the GDK toolbar, select **Deploy**.<br/><br/>
![GDK toolbar "Deploy" button]({{assetRoot}}assets/screen-grabs/toolbar/gdk-toolbar-deploy.png)<br/>
_Image: The GDK toolbar's **Deploy** button_<br/></br>
This opens the Cloud Deployment dialog box:</br></br>
<%(Lightbox title ="Cloud Deployment" image="{{assetRoot}}assets/screen-grabs/starter-template-deployment-launch.png")%>
<br/> _Image: The Cloud Deployment dialog box_<br/></br>

1. In the dialog box, enter the following information in the relevant fields:</br></br>
  * **Project Name**: The SpatialOS cloud project name you associated with your Unreal project in [Step 1](#step-1-associate-your-game-with-a-spatialos-cloud-project), above. </br>
(In the example it was `beta_yankee_hawaii_621`.) </br></br>
  * **Assembly Name**: The name you gave the assembly you uploaded in [Step 3](#step-3-upload-built-out-workers), above.
</br>
(In the example it was `myassembly`.)</br></br>
  * **Deployment Name**: You need to create a name for your deployment and add it here, this name labels the deployment in the Console.
</br>
(In the example dialog box shown, it's `mydeployment` but it can be whatever you choose and contain any alpha-numeric characters.)</br></br>
  * **Launch Config File**: The absolute filepath the your Unreal project's `.json` launch configuration file from `C:/`. </br>
  This is: `C:/...<filepath>.../<ProjectRoot>/spatial/one_worker_test.json`.
  <button class=\"collapsible\">What's the launch configuration file?</button>
<div>

This `.json` file contains the configuration parameters for starting a deployment, including:</br> * the game template - defines the compute resources your deployment needs (see the documentation on [game templates and pricing](https://docs.improbable.io/reference/latest/shared/pricing-and-support/pricing-details#introduction-to-game-templates)).</br> * `dimensionsInWorldUnits` - defines the size of your SpatialOS game world in X and Y.</br> * worker types - lists the worker type names you have set up for your project. For this project; an Unreal server-worker `UnrealWorker` and an Unreal client-worker `UnrealClient`.
</br></br>
This project comes with a ready-made launch configuration file `one_worker_test.json`. Note that you can call your launch configuration file any name you choose. </br>
You can find out more in the SpatialOS Worker SDK documentation: [launch confguration file](https://docs.improbable.io/reference/14.0/shared/flexible-project-layout/reference/launch-configuration) (but note that this may contain details on parameters not relevant to Unreal-developed projects).

</div>
  * **Snapshot File**: The absolute filepath to your project's `.snapshot` snapshot file from `C:/`. </br>
  This is: `C:/...<filepath>.../<ProjectRoot>/spatial/snapshots/default.snapshot`. </br></br>
  * **Region**: The real-world geographical location that you want your cloud deployment hosted in. </br>You can change this by selecting a different region from the drop-down list. You might prefer the region you are in.</br></br>
1. You can also choose to add simulated players via the dialogue box or skip this and move on to step 4.</br></br>
   Build out the simulated player clients using the following command.</br>
  Engine plugin filepath (default):</br></br>
  [block:code]
{
  "codes": [
  {
      "code": "UnrealEngine\\Engine\\Plugins\\UnrealGDK\\SpatialGDK\\Build\\Scripts\\BuildWorker.bat <YourProject>SimulatedPlayer Linux Development <YourProject>.uproject",
      "language": "text"
    }
  ]
}
[/block]
  Project plugin filepath:</br>
  [block:code]
{
  "codes": [
  {
      "code": "  <YourProject>\\Game\\Plugins\\UnrealGDK\\SpatialGDK\\Build\\Scripts\\BuildWorker.bat <YourProject>SimulatedPlayer Linux Development <YourProject>.uproject ",
      "language": "text"
    }
  ]
}
[/block]
  [block:html]
{
  "html": "<button class=\"collapsible\">Note: disabling game client plugins which don't run on Linux</button><div>\n\n\n\n  Simulated players run on Linux in the cloud. If your game clients use any plugins which don't run on Linux clients, you'll need to exclude them from building. This can be done in your game's Build.cs file, by wrapping any plugins that shouldn't be used on linux clients in a check like\n\n  `if (Target.Platform != UnrealTargetPlatform.Linux)`\n\n  </div>"
}
[/block]

  Then, back in the Editor Deploy window:</br></br>
  * **Add simulated players**: Check the box.</br></br>
  * **Deployment Name**: Enter a name for your simulated player deployment. This labels the deployment in the Console. Make it different to your game deployment name.</br></br>
  * **Number of Simulated Players**: Choose the number of simulated players you want to start. </br></br>
  * **Region**: The real-world geographical location that you want your simulated players cloud deployment hosted in. 
<button class=\"collapsible\">Tell me more about developing with simulated players</button>
<div>

There is a basic implementation of simulated players included with the Starter Template. You can find out more about setting up simulated players by: </br></br> *  Exploring the source code (look for `SimulatedPlayerCharacter_BP`).</br>*  Trying them out by deploying simulated players with this project.</br>*  Checking out the [simulated players]({{urlRoot}}/content/simulated-players) documentation. 
</div>
3. Select **Launch deployment**.</br>
Your deployment(s) won’t launch instantly - the Editor launches a console window which shows the progress of the deployment. </br>
When your deployment(s) have launched, you can open the Console at [console.improbable.io](https://console.improbable.io/) to view them.

> **Tip:** You can set default values for all the fields in the cloud deployment dialog box, using the Cloud section of the [SpatialOS Editor Settings panel]({{urlRoot}}/content/unreal-editor-interface/editor-settings).

<button class=\"collapsible\">Cloud deployment workflow summary</button>
<div>

There is a summary on when to update schema, how to build and upload workers, and how to launch your game on the [Cloud deployment workflow]({{urlRoot}}/content/cloud-deployment-workflow) page. It is the same as the one here.

[block:image]
{
  "images": [
    {
      "image": [
        "https://docs.google.com/drawings/d/e/2PACX-1vQVcAihbYTNe7TjNsIvkfqIR34Vgw5RESKxboxbvgY5VcgxiI-SZT_M2kuGE8RYMU6sAYWqdkoCjMWt/pub?w=758&h=1162",
        758,
        1162,
      ],
      "caption": ""
    }
  ]
}
[/block]


</div>

</br></br>

#### **> Next:** [4: Play the game]({{urlRoot}}/content/get-started/starter-template/get-started-template-play) 

<br/>

<br/>------------<br/>
_2019-11-14 Page updated without editorial review: added callout for plugins which won't run on Linux._<br/>
_2019-10-31 Page updated without editorial review: add missing build step for simulated player clients._<br/>
_2019-08-12 Page updated with editorial review: updated terms and narrative._<br/>
_2019-07-22 Page updated with limited editorial review._<br/>

[//]: # (TODO: https://improbableio.atlassian.net/browse/DOC-1241)