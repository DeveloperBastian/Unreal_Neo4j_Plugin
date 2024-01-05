### Bastian Developer ###

## Neo4J adapter for Epics Unreal ##

### Introduction ###
This is a project detailing the usage of Blueprints and a C++ class to connect to a Neo4J graph database.
It is supported by 
-	[presentation](https://docs.google.com/presentation/d/1w0KJltWo7U_tFZvoahYyqN6QoUCx9oEptdVMtumz03Y) to better detail some processes
-	a [video playlist](https://www.youtube.com/playlist?list=PLK0EcCQf_rravJ7KNry2N8RB8znd1A_jT) to document the development step by step - a german version of this playlist is available [here](https://www.youtube.com/playlist?list=PLK0EcCQf_rrZ4fPyU_fEonK-e8ytS8hHa)
-	a [summary HowTo video](https://youtu.be/Vj5TVYiRcSY)

## Steps to get started ##

### pull and start Neo4J from Docker###
### Windows ###
-	Install [Docker Desktop](https://www.docker.com/products/docker-desktop/) 
-	Reboot
-	run code below - replace the path to store data with your own path ("d:\neo4j" in my case)
```
docker run --name Unreal2Neo4j_Bitnami -p7474:7474 -p7687:7687 -d -v d:/neo4j/data:/data -v d:/neo4j/logs:/logs -v d:/neo4j/import:/var/lib/neo4j/import bitnami/neo4j:latest
```

### Linux ###
In Linux, replace the paths starting with "d:/"... e.g. with "$HOME/"

##Unreal Plugins to enable##
-	Json Blueprint Utilies (beta)

## Get started with a new project ##
-	Start a Third Character project - run and close
-	Copy the directory /Content/BA_Neo4j from this repository into your /Content folder or install the asset from the Epics Marketplace 
-	Open the map 'Neo4J_TestMap' from the /Plugins//BA_Neo4j/Maps
	![demo map](/Resources/images/demo_map.png)
	
-	The Map uses Actors with onOverlap events to go through different use cases:
	-	installing the Neo4j Actor Component
	-	querying the database for some meta information such as Neo4j version
	-	installing 5 bases node from the DataTable 'DT_BaseNodes'
		![5 nodes example](/Resources/images/5_node_example.png)
	-	installing 99 nodes from the periodic system elements from the DataTable 'DT_PeriodicSystemElements'
		![99 nodes example](/Resources/images/99_node_example.png)
	-	getting all nodes from the db
	-	deleting all nodes from the database
- **IMPORTANT**: Open the Data Table DT_Connections and modify a connection to be active and store your username/pwd there
- Already predefined are: No Authentication, Neo4j Standard (neo4j:neo4j), Bitnami default (neo4j:bitnami1)	

## Licenses ##
All work released here is under [Creative Common license](https://creativecommons.org/licenses/by/4.0/)
