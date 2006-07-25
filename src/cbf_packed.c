/**********************************************************************
 * cbf_packed -- Packing compression                                  *
 *                                                                    *
 * Version 0.7.2 22 April 2001                                        *
 *                                                                    *
 *            Paul Ellis (ellis@ssrl.slac.stanford.edu) and           *
 *         Herbert J. Bernstein (yaya@bernstein-plus-sons.com)        *
 **********************************************************************/
  
/**********************************************************************
 *                               NOTICE                               *
 * Creative endeavors depend on the lively exchange of ideas. There   *
 * are laws and customs which establish rights and responsibilities   *
 * for authors and the users of what authors create.  This notice     *
 * is not intended to prevent you from using the software and         *
 * documents in this package, but to ensure that there are no         *
 * misunderstandings about terms and conditions of such use.          *
 *                                                                    *
 * Please read the following notice carefully.  If you do not         *
 * understand any portion of this notice, please seek appropriate     *
 * professional legal advice before making use of the software and    *
 * documents included in this software package.  In addition to       *
 * whatever other steps you may be obliged to take to respect the     *
 * intellectual property rights of the various parties involved, if   *
 * you do make use of the software and documents in this package,     *
 * please give credit where credit is due by citing this package,     *
 * its authors and the URL or other source from which you obtained    *
 * it, or equivalent primary references in the literature with the    *
 * same authors.                                                      *
 *                                                                    *
 * Some of the software and documents included within this software   *
 * package are the intellectual property of various parties, and      *
 * placement in this package does not in any way imply that any       *
 * such rights have in any way been waived or diminished.             *
 *                                                                    *
 * With respect to any software or documents for which a copyright    *
 * exists, ALL RIGHTS ARE RESERVED TO THE OWNERS OF SUCH COPYRIGHT.   *
 *                                                                    *
 * Even though the authors of the various documents and software      *
 * found here have made a good faith effort to ensure that the        *
 * documents are correct and that the software performs according     *
 * to its documentation, and we would greatly appreciate hearing of   *
 * any problems you may encounter, the programs and documents any     *
 * files created by the programs are provided **AS IS** without any   *
 * warranty as to correctness, merchantability or fitness for any     *
 * particular or general use.                                         *
 *                                                                    *
 * THE RESPONSIBILITY FOR ANY ADVERSE CONSEQUENCES FROM THE USE OF    *
 * PROGRAMS OR DOCUMENTS OR ANY FILE OR FILES CREATED BY USE OF THE   *
 * PROGRAMS OR DOCUMENTS LIES SOLELY WITH THE USERS OF THE PROGRAMS   *
 * OR DOCUMENTS OR FILE OR FILES AND NOT WITH AUTHORS OF THE          *
 * PROGRAMS OR DOCUMENTS.                                             *
 **********************************************************************/
 
/**********************************************************************
 *                                                                    *
 *                           The IUCr Policy                          *
 *      for the Protection and the Promotion of the STAR File and     *
 *     CIF Standards for Exchanging and Archiving Electronic Data     *
 *                                                                    *
 * Overview                                                           *
 *                                                                    *
 * The Crystallographic Information File (CIF)[1] is a standard for   *
 * information interchange promulgated by the International Union of  *
 * Crystallography (IUCr). CIF (Hall, Allen & Brown, 1991) is the     *
 * recommended method for submitting publications to Acta             *
 * Crystallographica Section C and reports of crystal structure       *
 * determinations to other sections of Acta Crystallographica         *
 * and many other journals. The syntax of a CIF is a subset of the    *
 * more general STAR File[2] format. The CIF and STAR File approaches *
 * are used increasingly in the structural sciences for data exchange *
 * and archiving, and are having a significant influence on these     *
 * activities in other fields.                                        *
 *                                                                    *
 * Statement of intent                                                *
 *                                                                    *
 * The IUCr's interest in the STAR File is as a general data          *
 * interchange standard for science, and its interest in the CIF,     *
 * a conformant derivative of the STAR File, is as a concise data     *
 * exchange and archival standard for crystallography and structural  *
 * science.                                                           *
 *                                                                    *
 * Protection of the standards                                        *
 *                                                                    *
 * To protect the STAR File and the CIF as standards for              * 
 * interchanging and archiving electronic data, the IUCr, on behalf   *
 * of the scientific community,                                       *
 *                                                                    *
 * * holds the copyrights on the standards themselves,                *
 *                                                                    *
 * * owns the associated trademarks and service marks, and            *
 *                                                                    *
 * * holds a patent on the STAR File.                                 *
 *                                                                    *
 * These intellectual property rights relate solely to the            *
 * interchange formats, not to the data contained therein, nor to     *
 * the software used in the generation, access or manipulation of     *
 * the data.                                                          *
 *                                                                    *
 * Promotion of the standards                                         *
 *                                                                    *
 * The sole requirement that the IUCr, in its protective role,        *
 * imposes on software purporting to process STAR File or CIF data    *
 * is that the following conditions be met prior to sale or           *
 * distribution.                                                      *
 *                                                                    *
 * * Software claiming to read files written to either the STAR       *
 * File or the CIF standard must be able to extract the pertinent     *
 * data from a file conformant to the STAR File syntax, or the CIF    *
 * syntax, respectively.                                              *
 *                                                                    *
 * * Software claiming to write files in either the STAR File, or     *
 * the CIF, standard must produce files that are conformant to the    *
 * STAR File syntax, or the CIF syntax, respectively.                 *
 *                                                                    *
 * * Software claiming to read definitions from a specific data       *
 * dictionary approved by the IUCr must be able to extract any        *
 * pertinent definition which is conformant to the dictionary         *
 * definition language (DDL)[3] associated with that dictionary.      *
 *                                                                    *
 * The IUCr, through its Committee on CIF Standards, will assist      *
 * any developer to verify that software meets these conformance      *
 * conditions.                                                        *
 *                                                                    *
 * Glossary of terms                                                  *
 *                                                                    *
 * [1] CIF:  is a data file conformant to the file syntax defined     *
 * at http://www.iucr.org/iucr-top/cif/spec/index.html                *
 *                                                                    *
 * [2] STAR File:  is a data file conformant to the file syntax       *
 * defined at http://www.iucr.org/iucr-top/cif/spec/star/index.html   *
 *                                                                    *
 * [3] DDL:  is a language used in a data dictionary to define data   *
 * items in terms of "attributes". Dictionaries currently approved    *
 * by the IUCr, and the DDL versions used to construct these          *
 * dictionaries, are listed at                                        *
 * http://www.iucr.org/iucr-top/cif/spec/ddl/index.html               *
 *                                                                    *
 * Last modified: 30 September 2000                                   *
 *                                                                    *
 * IUCr Policy Copyright (C) 2000 International Union of              *
 * Crystallography                                                    *
 **********************************************************************/

#ifdef __cplusplus

extern "C" {

#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "cbf.h"
#include "cbf_alloc.h"
#include "cbf_compress.h"
#include "cbf_file.h"
#include "cbf_packed.h"

#define CBF_SHIFT63 (sizeof (int) * CHAR_BIT > 64 ? 63 : 0)

typedef struct
{
  int offset [128][2];

  unsigned int size [128];

  unsigned int start;

  unsigned int offsets;
}
cbf_packed_data;

#define CBF_PACKED_BITS1  4
#define CBF_PACKED_BITS2  5
#define CBF_PACKED_BITS3  6
#define CBF_PACKED_BITS4  7
#define CBF_PACKED_BITS5  8
#define CBF_PACKED_BITS6  16

#define CBF_PACKED_MASK1  ~15
#define CBF_PACKED_MASK2  ~31
#define CBF_PACKED_MASK3  ~63
#define CBF_PACKED_MASK4  ~127
#define CBF_PACKED_MASK5  ~255
#define CBF_PACKED_MASK6  ~65535

static const unsigned int cbf_packed_bits [8] = { 0, CBF_PACKED_BITS1,
                                                     CBF_PACKED_BITS2,
                                                     CBF_PACKED_BITS3,
                                                     CBF_PACKED_BITS4,
                                                     CBF_PACKED_BITS5,
                                                     CBF_PACKED_BITS6, 65 };


  /* Add an integer to the array of offsets to write */

int cbf_add_offset (cbf_packed_data *data, unsigned int element,
                                           unsigned int last_element)
{
  int offset;
  
  unsigned int index, m;


    /* Save the offset */

  index = (data->offsets + data->start) & 127;

  offset = element - last_element;
    
  data->offset [index][0] = offset;


    /* How many bits do we need to save? */

  if (offset == 0)

    data->size [index] = 0;

  else

    if ((element < last_element && offset > 0) ||
        (element > last_element && offset < 0))
    {
      data->offset [index][1] = -(offset > 0);

      data->size [index] = 7;
    }
    else
    {
      m = (offset ^ (offset << 1));

      if ((m & CBF_PACKED_MASK1) == 0)

        data->size [index] = 1;

      else

        if ((m & CBF_PACKED_MASK2) == 0)

          data->size [index] = 2;

        else

          if ((m & CBF_PACKED_MASK3) == 0)

            data->size [index] = 3;

          else

            if ((m & CBF_PACKED_MASK4) == 0)

              data->size [index] = 4;

            else

              if ((m & CBF_PACKED_MASK5) == 0)

                data->size [index] = 5;

             else

               if ((m & CBF_PACKED_MASK6) == 0)

                 data->size [index] = 6;

               else

                 data->size [index] = 7;
    }

  
    /* Success */

  data->offsets++;

  return 0;
}


  /* Pack 1 << chunk offsets in [size] bits each */

int cbf_pack_chunk (cbf_packed_data *data, int size, int chunk, 
                                           cbf_file *file,
                                           unsigned long *bitcount)
{
  unsigned int count, index;


    /* Write the codes */

  cbf_failnez (cbf_put_integer (file, (size << 3) | chunk, 0, 6))

  chunk = 1 << chunk;

  if (size > 0)
  {
    index = data->start;
    
    for (count = chunk; count; count--, index++)

      cbf_failnez (cbf_put_bits (file, data->offset [index & 127], 
                                       cbf_packed_bits [size]))
  }


    /* Update the buffer count and start */

  data->start = (data->start + chunk) & 127;

  data->offsets -= chunk;


    /* Calculate the number of bits written */
    
  if (bitcount)
  
    if (size)
    
      *bitcount = 6 + chunk * cbf_packed_bits [size];
      
    else
    
      *bitcount = 6;


    /* Success */

  return 0;
}


  /* Get the maximum size required to code 1 << chunk offsets */

unsigned int cbf_maximum_size (cbf_packed_data *data, unsigned int start,
                                                      unsigned int chunk)
{
  unsigned int maxsize, index, count;


    /* Get the maximum size */

  maxsize = 0;

  index = data->start + start;

  for (count = 1 << chunk; count; count--)
  {
    if (data->size [index & 127] > maxsize)

      maxsize = data->size [index & 127];
    
    index++;
  }
  
  return maxsize;
}


  /* Write out a block as economically as possible */

int cbf_pack_nextchunk (cbf_packed_data *data, cbf_file *file, 
                                               unsigned long *bitcount)
{
  unsigned int bits, next_bits, chunk, size, next_size,
               combined_bits, combined_size;


    /* Number of bits to encode a single offset */

  size = cbf_maximum_size (data, 0, 0);

  bits = cbf_packed_bits [size] + 6;


  chunk = 0;

  while (data->offsets >= (2 << chunk))
  {
    next_size = cbf_maximum_size (data, 1 << chunk, chunk);

    next_bits = (cbf_packed_bits [next_size] << chunk) + 6;

    if (size > next_size)
    {
      combined_bits = bits * 2 - 6;

      combined_size = size;
    }
    else
    {
      combined_bits = next_bits * 2 - 6;

      combined_size = next_size;
    }

    if (combined_bits > bits + next_bits)

      return cbf_pack_chunk (data, size, chunk, file, bitcount);

    bits = combined_bits;

    size = combined_size;

    chunk++;
  }

  return cbf_pack_chunk (data, size, chunk, file, bitcount);
}


  /* Compress an array */
  
int cbf_compress_packed (void         *source, 
                         size_t        elsize, 
                         int           elsign, 
                         size_t        nelem, 
                         unsigned int  compression, 
                         cbf_file     *file, 
                         size_t       *compressedsize,
                         int          *storedbits)
{
  unsigned int minelement, maxelement;

  unsigned int count, element, lastelement, unsign, sign, limit;

  unsigned char *unsigned_char_data;
  
  unsigned long bitcount, chunkbits;

  cbf_packed_data *data;


    /* Is the element size valid? */
    
  if (elsize != sizeof (int) &&
      elsize != sizeof (short) &&
      elsize != sizeof (char))

    return CBF_ARGUMENT;


    /* Allocate memory */

  cbf_failnez (cbf_alloc ((void **) &data, NULL, sizeof (cbf_packed_data), 1))

  data->start = 0;

  data->offsets = 0;


    /* Count the expected number of bits */

  minelement = 0;

  maxelement = 0;
 
 
    /* Write the number of elements (64 bits) */

  cbf_onfailnez (cbf_put_integer (file, nelem, 0, 64),
                 cbf_free ((void **) data, NULL))


    /* Write the minimum element (64 bits) */

  cbf_onfailnez (cbf_put_integer (file, minelement, elsign, 64),
                 cbf_free ((void **) data, NULL))


    /* Write the maximum element (64 bits) */

  cbf_onfailnez (cbf_put_integer (file, maxelement, elsign, 64),
                 cbf_free ((void **) data, NULL))


    /* Write the reserved entry (64 bits) */

  cbf_onfailnez (cbf_put_integer (file, 0, 0, 64),
                 cbf_free ((void **) data, NULL))

  bitcount = 4 * 64;
  

    /* Initialise the pointers */

  unsigned_char_data = (unsigned char *) source;


    /* Maximum limit (unsigned) is 64 bits */

  if (elsize * CHAR_BIT > 64)
  {
    sign = 1 << CBF_SHIFT63;

    limit = ~-(sign << 1);

    if (storedbits)
    
      *storedbits = 64;
  }
  else
  {
    sign = 1 << (elsize * CHAR_BIT - 1);

    limit = ~0;

    if (storedbits)
    
      *storedbits = elsize * CHAR_BIT;
  }


    /* Offset to make the value unsigned */

  if (elsign)

    unsign = sign;

  else

    unsign = 0;


    /* Start from 0 */

  lastelement = unsign;

  for (count = 0; count < nelem; count++)
  {
      /* Get the next element */

    if (elsize == sizeof (int))

      element = *((unsigned int *) unsigned_char_data);

    else

      if (elsize == sizeof (short))

        element = *((unsigned short *) unsigned_char_data);

      else

        element = *unsigned_char_data;

    unsigned_char_data += elsize;


      /* Make the element unsigned */

    element += unsign;


      /* Limit the value to 64 bits */

    if (element > limit)

      if (elsign && (int) (element - unsign) < 0)

        element = 0;

      else

        element = limit;


      /* Add the offset to the buffer */

    cbf_add_offset (data, element, lastelement);


      /* Is the buffer full? */

    if (data->offsets == 128)
    {
        /* Write the next block as economically as possible */

      cbf_onfailnez (cbf_pack_nextchunk (data, file, &chunkbits),
                     cbf_free ((void **) data, NULL))
                 
      bitcount += chunkbits;
    }


      /* Update the previous element */
        
    lastelement = element;
  }


    /* Flush the buffers */

  while (data->offsets > 0)
  {
    cbf_onfailnez (cbf_pack_nextchunk (data, file, &chunkbits),
                   cbf_free ((void **) data, NULL))
               
    bitcount += chunkbits;
  }


    /* Return the number of characters written */
    
  if (compressedsize)
  
    *compressedsize = (bitcount + 7) / 8;
    

    /* Free memory */

  return cbf_free ((void **) &data, NULL);
}


  /* Decompress an array */

int cbf_decompress_packed (void         *destination, 
                           size_t        elsize, 
                           int           elsign, 
                           size_t        nelem, 
                           size_t       *nelem_read,
                           unsigned int  compression, 
                           cbf_file     *file)
{
  unsigned int next, pixel, pixelcount;

  unsigned int bits, element, sign, unsign, limit, count64, count;

  unsigned char *unsigned_char_data;

  unsigned int offset [4], last_element [4];

  int errorcode;


    /* Is the element size valid? */
    
  if (elsize != sizeof (int) &&
      elsize != sizeof (short) &&
      elsize != sizeof (char))

    return CBF_ARGUMENT;


    /* Initialise the pointer */

  unsigned_char_data = (unsigned char *) destination;


    /* Maximum limit (unsigned) is 64 bits */

  if (elsize * CHAR_BIT > 64)
  {
    sign = 1 << CBF_SHIFT63;

    limit = ~-(sign << 1);
  }
  else
  {
    sign = 1 << (elsize * CHAR_BIT - 1);

    if (elsize == sizeof (int))

      limit = ~0;

    else

      limit = ~-(1 << (elsize * CHAR_BIT));
  }


    /* Offset to make the value unsigned */

  if (elsign)

    unsign = sign;

  else

    unsign = 0;


    /* How many ints do we need to hold 64 bits? */

  count64 = (64 + sizeof (int) * CHAR_BIT - 1) / (sizeof (int) * CHAR_BIT);


    /* Initialise the first element */

  last_element [0] = unsign;

  for (count = 1; count < count64; count++)
        
    last_element [count] = 0;


    /* Discard the reserved entry (64 bits) */

  cbf_failnez (cbf_get_integer (file, NULL, 0, 64))


    /* Read the elements */

  count = 0;

  while (count < nelem)
  {
      /* Get the next 6 bits of data */

    errorcode = cbf_get_integer (file, (int *) &next, 0, 6);

    if (errorcode)
    {
      if (nelem_read)

        *nelem_read = count + pixel;
          
      return errorcode;
    }


      /* Decode bits 0-5 */

    pixelcount = 1 << (next & 7);

    bits = cbf_packed_bits [(next >> 3) & 7];


      /* Read the offsets */

    if (pixelcount + count > nelem)

      pixelcount = nelem - count;

    for (pixel = 0; pixel < pixelcount; pixel++)
    {
        /* Read an offset */

      if (bits)
      {
        errorcode = cbf_get_bits (file, (int *) offset, bits);

        if (errorcode)
        {
          if (nelem_read)

            *nelem_read = count + pixel;
          
          return errorcode;
        }


          /* Update the current element */

        last_element [0] += offset [0];
      }

      element = last_element [0];


        /* Limit the value to fit the element size */

      if (element > limit)

        if (elsign && (int) (element - unsign) < 0)

          element = 0;

        else

          element = limit;


        /* Make the element signed? */

      element -= unsign;


        /* Save the element */

      if (elsize == sizeof (int))

        *((unsigned int *) unsigned_char_data) = element;

      else

        if (elsize == sizeof (short))

          *((unsigned short *) unsigned_char_data) = element;

        else

          *unsigned_char_data = element;

      unsigned_char_data += elsize;
    }

    count += pixelcount;
  }


    /* Number read */

  if (nelem_read)
  
    *nelem_read = count;


    /* Success */

  return 0;
}


#ifdef __cplusplus

}

#endif