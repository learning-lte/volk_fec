#ifndef INCLUDED_volk_fec_16i_x2_calc_euclidean_metricpuppet_16i_u_H
#define INCLUDED_volk_fec_16i_x2_calc_euclidean_metricpuppet_16i_u_H

#include <inttypes.h>
#include <stdio.h>
#include <volk_fec/volk_fec.h>
#include <volk_fec/volk_fec_16i_x2_calc_euclidean_metric_16i.h>

#ifdef LV_HAVE_GENERIC
/*! 
  \brief calculates euclidean metric for two input vectors and stores their
         their result a the third vector
  \param O FSM Output cardinality
  \param D Dimensionality of input vector
  \param table Vector with valid symbols
  \param input Input vector
  \param metric Metrics are stored in this vector
*/

static inline void volk_fec_16i_x2_calc_euclidean_metricpuppet_16i_generic(short *c_vector,
                                                    const short *a_vector,
                                                    const short *b_vector,
                                                    unsigned int num_points)
{
    short *metrics;
    metrics = (short*) volk_fec_malloc(num_points*4*sizeof(short), volk_fec_get_alignment()); 
    volk_fec_16i_x2_calc_euclidean_metric_16i_manual(metrics, a_vector, b_vector,
                                                   4, 1, num_points, "generic");
    volk_fec_free(metrics);
}

#endif /* LV_HAVE_GENERIC */
#endif /* INCLUDED_volk_fec_16i_x2_calc_euclidean_metricpuppet_16i_u_H */

#ifndef INCLUDED_volk_fec_16i_x2_calc_euclidean_metricpuppet_16i_a_H
#define INCLUDED_volk_fec_16i_x2_calc_euclidean_metricpuppet_16i_a_H

#include <inttypes.h>
#include <stdio.h>
#include <volk_fec/volk_fec.h>
#include <volk_fec/volk_fec_16i_x2_calc_euclidean_metric_16i.h>

#ifdef LV_HAVE_SSE4_1

#include <xmmintrin.h>
#include <emmintrin.h>
#include <smmintrin.h>
#include <tmmintrin.h>
/*! 
  \brief calculates euclidean metric for two input vectors and stores their
         their result a the third vector
  \param c_vector Output metrics vector 
  \param a_vector Input vector
  \param b_vector Symbol table
  \param O Symbol cardinality
  \param D Smybol dimensionality
*/

static inline void volk_fec_16i_x2_calc_euclidean_metricpuppet_16i_a_sse4(short *c_vector,
                                                    const short *a_vector,
                                                    const short *b_vector,
                                                    unsigned int num_points)
{
    short *metrics;
    metrics = (short*) volk_fec_malloc(num_points*4*sizeof(short), volk_fec_get_alignment()); 
    volk_fec_16i_x2_calc_euclidean_metric_16i_manual(metrics, a_vector, b_vector,
                                                   4, 1, num_points, "a_sse4");
    volk_fec_free(metrics);
}

#endif /* LV_HAVE_SSE4_1 */
#endif /* INCLUDED_volk_fec_16i_x2_calc_euclidean_metricpuppet_16i_a_H */