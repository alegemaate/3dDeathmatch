varying vec4 diffuse, ambientGlobal, ambient, ecPos;
varying vec3 normal, halfVector;

uniform sampler2D texture1;

void main()
{
	vec4 texture_info = texture2D( texture1, gl_TexCoord[0].st);
  vec3 n, halfV, lightDir;
  float NdotL, NdotHV;
  vec4 color = ambientGlobal;
  float att, dist;

  /* a fragment shader can't write a verying variable, hence we need
  a new variable to store the normalized interpolated normal */
  n = normalize( normal);

  // Compute the ligt direction
  lightDir = vec3( gl_LightSource[0].position - ecPos);

  /* compute the distance to the light source to a varying variable*/
  dist = length( lightDir);

  /* compute the dot product between normal and ldir */
  NdotL = max( dot( n, normalize( lightDir)), 0.0);

  if( NdotL > 0.0) {
    att = 1.0 / ( gl_LightSource[0].constantAttenuation +
                  gl_LightSource[0].linearAttenuation * dist +
                  gl_LightSource[0].quadraticAttenuation * dist * dist);
    color += att * ( diffuse * NdotL + ambient);

    halfV = normalize( halfVector);
    NdotHV = max( dot( n, halfV), 0.0);
    color += att * gl_FrontMaterial.specular * gl_LightSource[0].specular * pow(NdotHV,gl_FrontMaterial.shininess);
  }

  gl_FragColor = color * texture_info;
}
