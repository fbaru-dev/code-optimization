.PHONY: all clean

CFLAGS  += -fopenmp
LDFLAGS += -lX11

PROGRAMS = mandelbrot
SOURCES = mandelbrot.c
OBJS = $(SOURCES:%.c=%.o)
COMPILE = $(CC) -c $(CPPFLAGS) $(CFLAGS)
LINK = $(LD) -fopenmp

DEPDIR = .deps
df = $(DEPDIR)/$(*F)

all: $(PROGRAMS)

$(PROGRAMS): $(OBJS)
	@echo "[LD]" $@
	$(LINK) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.c
	@echo "[CC]" $<
	@$(MKDIR_P) $(DEPDIR)
	$(COMPILE) -MD -o $@ $<
	@cp $*.d $(df).P; \
sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
-e '/^$$/ d' -e 's/$$/ :/' < $*.d >> $(df).P; \
rm -f $*.d

-include $(SOURCES:%.c=$(DEPDIR)/%.P)

clean:
	$(RM) -rf $(DEPDIR)
	$(RM) -f $(OBJS) $(PROGRAMS)
