# video-converter
App to convert videos to different formats

# Development instructions
All the project is configured to be compiled on containers. Execute

```
docker compose build compute-debug
```

for a debug version

```
docker compose build compute-release
``` 

for a release version.

You can execute the compute node server by executing 

```
docker compose run --rm compute-{debug/release} ./build/video-converter-compute
``` 

on the debug or release compilations, or you can execute the production container

```
docker compose run --rm compute-runtime
```

Contact: miguelgodon@outlook.es 

