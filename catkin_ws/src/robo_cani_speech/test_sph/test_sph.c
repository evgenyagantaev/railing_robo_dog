#include <pocketsphinx.h>

int main(int argc, char *argv[])
{
    ps_decoder_t *ps;

    cmd_ln_t *config;

    FILE *fh;

    char const *hyp, *uttid;

    int16 buf[2048];

    int rv;

    int32 score;

    config = cmd_ln_init(NULL, ps_args(), TRUE,
                "-samprate", "8000",
		        "-hmm", "zero_ru.cd_cont_4000",
		        //"-lm", "ru.lm",
	    		"-dict", "test_dictionary.dic",
                "-kws", "test_kwslist.kwslist",
		        NULL);

    if (config == NULL) 
    {
        fprintf(stderr, "Failed to create config object, see log for details\n");
        return -1;
    }

    ps = ps_init(config);
    if (ps == NULL) 
    {
        fprintf(stderr, "Failed to create recognizer, see log for details\n");
        return -1;
    }

    //**********************************************************************
    fh = fopen("test_test.wav", "rb");
    printf("<<< FOPEN\n");
    if (fh == NULL) 
    {
        fprintf(stderr, "Unable to open input file test_test.wav\n");
        return -1;
    }

    rv = ps_start_utt(ps);

    while (!feof(fh)) 
    {
        size_t nsamp;
        nsamp = fread(buf, 2, 2048, fh);
        rv = ps_process_raw(ps, buf, nsamp, FALSE, FALSE);
    }

    rv = ps_end_utt(ps);
    hyp = ps_get_hyp(ps, &score);
    printf("Recognized: %s\n", hyp);

    fclose(fh);
    printf("FCLOSE >>>\n");
    //***********************************************************************
    ps_free(ps);
    cmd_ln_free_r(config);

    return 0;
}