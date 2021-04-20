/* -*- mode: C -*-  */
/* 
   IGraph library.
   Copyright (C) 2010-2012  Gabor Csardi <csardi.gabor@gmail.com>
   334 Harvard street, Cambridge, MA 02139 USA
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc.,  51 Franklin Street, Fifth Floor, Boston, MA 
   02110-1301 USA

*/

#include <igraph.h>
#include <igraph_attributes.h>


void show_results(igraph_t *g, igraph_vector_t *mod, igraph_matrix_t *merges, FILE* f) {
	long int i;
	igraph_vector_t membership;
	
	igraph_vector_init(&membership, 0);
	
	i=igraph_vector_which_max(mod);
	fprintf(f, "Modularity:  %f\n", VECTOR(*mod)[i]);
	/* igraph_community_to_membership(merges, igraph_vcount(g), i, &membership, 0);
	printf("Membership: ");
	for (i=0; i<igraph_vector_size(&membership); i++) {
		printf("%li ", (long int)VECTOR(membership)[i]);
	}
	printf("\n"); */
	
	igraph_vector_destroy(&membership);
}

/* void prepare_weights_vector(igraph_vector_t* weights, const igraph_t* graph) {

	
	igraph_i_set_attribute_table(&igraph_cattribute_table);


	printf("Edges: %li\n", (long int) igraph_ecount(&graph));

  //for (k = 0; k < n; k++) {
  //  VECTOR(*weights)[k] = k % 5;
  //}
	EANV(graph, "weight", &weights);
} */

int main (int argc, char *argv[]){

	igraph_vector_t v;

	//igraph_real_t pesos[] = {0.92214, 0.909076, 0.962038, 0.941091, 0.90772, 0.913146, 0.959494, 0.95744, 0.948636, 0.93724, 0.901822, 0.943401, 0.917174, 0.939108, 0.934815, 0.94643, 0.925001, 0.929452, 0.935894, 0.901814, 0.954296, 0.942067, 0.965042, 0.969607, 0.957594, 0.968414}; 
  
	igraph_vector_t modularity, weights;
	igraph_matrix_t merges;
	
	igraph_vector_init(&modularity,0);
	igraph_matrix_init(&merges,0,0);
	igraph_vector_init(&weights,0);
	
	igraph_vector_t membership;
	//igraph_vector_t weights;
	//igraph_vector_t modularity;
	//igraph_real_t modularity;
	igraph_bool_t simple;
	
	//igraph_matrix_t merges;
	
	int retval;
	int a;
	double *my_array[251];
    
	igraph_t g;
	FILE *ifile;

	igraph_i_set_attribute_table(&igraph_cattribute_table);
	
	/* PAJEK */
	ifile=fopen(argv[1], "r");
	if (ifile==0) {
		return 10;
	}
	igraph_read_graph_pajek(&g, ifile);
	fclose(ifile);

	int ne = igraph_ecount(&g);
	igraph_vector_init(&weights,1); 
	
	igraph_vector_resize(&weights, ne);

	// prepare_weights_vector(&weights, &g);
	
	EANV(&g, "weight", &weights);
	
	igraph_vector_init(&membership, 0);

	// igraph_set_error_handler(&igraph_error_handler_printignore);

	//igraph_community_optimal_modularity(&g, &modularity, &membership, &weights);
	igraph_community_fastgreedy(&g, &weights, &merges, &modularity, /*membership=*/ 0);
	
	
	// igraph_modularity(const igraph_t *graph, const igraph_vector_t *membership, igraph_real_t *modularity, const igraph_vector_t *weights);
	
	long int k;
	//igraph_vector_t membership;
	
	//igraph_vector_init(&membership, 0);
	
	k=igraph_vector_which_max(&modularity);
	printf("%f\n", VECTOR(modularity)[k]);
	/* for (int i=0; i<igraph_vector_size(&membership); i++) {
		fprintf(stdout, " %li", (long int) VECTOR(membership)[i]);
	}
	printf("\n"); */
	//show_results(&g, &modularity, &merges, stdout); 
	igraph_destroy(&g);
	
	igraph_vector_destroy(&membership);
	igraph_vector_destroy(&modularity);
	igraph_vector_destroy(&weights);
	igraph_matrix_destroy(&merges);

	return 0;
}

// 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 3, 2, 1, 1, 2, 2, 19, 4, 6, 2, 3, 1, 1, 2, 2, 3, 2, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 2, 1, 3, 1, 1, 2, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 2, 1, 1, 2, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 41, 14, 1, 1, 1, 1, 1, 2, 1, 2, 16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 3, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
