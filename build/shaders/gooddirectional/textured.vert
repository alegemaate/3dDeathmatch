void main()
{
	vec3 normal, lightDir, viewVector, halfVector;
	vec4 diffuse, ambient, globalAmbient, specular = vec4(0.0);
	float NdotL,NdotHV;

  normal = normalize(gl_NormalMatrix * gl_Normal);

	// Lighting
  lightDir = normalize(vec3(gl_LightSource[0].position));
	NdotL = max(dot(normal, lightDir), 0.0);

	// Diffuse
	diffuse = gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse;

	// Ambient
	ambient = gl_FrontMaterial.ambient * gl_LightSource[0].ambient;
	globalAmbient = gl_LightModel.ambient * gl_FrontMaterial.ambient;

	// Specular
	if (NdotL > 0.0) {
  	// normalize the half-vector, and then compute the cosine (dot product) with the normal
 		NdotHV = max(dot(normal, gl_LightSource[0].halfVector.xyz),0.0);
    specular = gl_FrontMaterial.specular * gl_LightSource[0].specular *
      pow(NdotHV,gl_FrontMaterial.shininess);
	}

	gl_FrontColor =  NdotL * diffuse + globalAmbient + ambient + specular;

  //gl_TexCoord[0] = gl_MultiTexCoord0;
  gl_Position = ftransform();
}