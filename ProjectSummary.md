# Why? - From [Greg Gluszek](https://github.com/greggersaurus)

You may be wondering why this project exists and why I have invested a
non-negligible amount of my time and energy into it over the past couple of
years.

First, I found the design of this controller to be compelling. Having two
trackpads in place of the D-pad and right analog stick is an interesting idea.
The trackpads can be configured to act in a variety of ways and not only
mimic what they replaced, but also provide new interaction paradigms. Also,
the idea of using the  haptics to play a little Jingle when the controller
starts up or shuts down is a neat touch that made the controller further
stand out. Being able to fully customize these Jingles was a near immediate
desire when I first started using the controller.

Second, the controller was left fairly accessible. Being able to upload
firmware updates manually made the barrier to entry for running custom
firmware much lower. There was still a considerable challenge to get even
a "Hello World" (i.e. blink the Steam Button LED) working. However, this was
not nearly as tough as I imagine doing something similar on a controller
that is designed to be more temper resistant would be. I really appreciate
the fact that Valve left this hardware as accessible as they did and do
not discourage people from trying to hack it.

Third, iFixit did a really nice [teardown](https://www.ifixit.com/Teardown/Steam+Controller+Teardown/52578)
of the controller. This gave me an idea of what the controller had going on
internally, without needing to (initially) take apart my hardware. This
pointed out a lot of neat peripherals and processors that I thought would
be neat to work with, especially in the context of a product that already
was designed for a particular purpose.

# The Open Steam Controller Project - Summary From [Greg Gluszek](https://github.com/greggersaurus)

Now that the controller and some of its (default) capabilities have been explained,
we can start talking about this project. Namely I want to cover what has been
accomplished, and what I hope to accomplish moving forward.

Note, the following is a bit verbose and narrative. There is a lot of content
in this project and this is an attempt to break down the details in a way that will
give an easy to follow lay of the land for people new to this effort. If you are a TLDR kind
of person, check out the Notice and Warning Section below and then feel free to
jump into the Subprojects Section to get to the meat of effort. You should also be sure to
check out the demo videos that show some of the major accomplishments in action.

As mentioned previously, the primary intention of this project is to explore, deconstruct and
expand upon configuration options and usages for the Steam Controller. However,
that is a bit vague. So let's start with some examples. First, a major goal
of this project was to be able to write custom firmware for the main processor
on the controller. This is what opens up the door for a lot of other
possibilities moving forward.

However, before I could start writing firmware I needed more
info on the controller. Valve was nice enough to leave the door open to
accessing the binary version of their firmware and the ability to update
the main processor easily. However, they did not provide schematics or
a list of components or datasheets that an embedded software engineer
would typically have if tasked with the process of writing custom
firmware. Therefore, I needed to turn to reverse engineering. This essentially
boils down to deconstructing the hardware and official firmware so that I
could understand how to write my own firmware. At this point the Reverse
Engineering effort has mostly run its course, as a lot has been discovered,
documented and utilized for other efforts. Details on the Reverse Engineering
effort can be found in the [Reverse Engineering Subproject](./ReverseEngineering/).

Now that a Reverse Engineering effort has been established and I
have started gathering information on the hardware, I was able to start writing
custom Firmware. Check out the [Firmware Subproject](./Firmware/) to see the current
state of software. Mostly this is utility software to allow a user to
query different peripherals or take measurements at different states (as
some of that information needed to be captured and fed back into the Reverse
Engineering process to keep it moving forward). However, it eventually became
clear that there was enough functionality that was captured here that it would not
be too much additional work to make this hardware act as a controller for
other consoles (i.e. the Nintendo Switch).

Next we come to what was originally the sole intention of this project. That is,
the goal of being able to have full control of the songs (Jingles) that the
Steam Controller plays (via the Trackpad Haptics) on power up and shut down.
Due to some discoveries via the Reverse Engineering effort, this project
allows for Jingles to be fully customized and for these customizations to
persist while still running Valve's official firmware. For details on how
to customize the Jingles on your controller, or for more details (i.e. how Jingle
Data is formatted and how we can customize Jingles without modifying the official
firmware) see The [Jingles Subproject](./Mods/Jingle).

Finally, it is important to mention that another intention of this project is
for it to to be an educational and/or motivational resource. Maybe you are
interested in the Steam Controller. Or maybe you are interested in writing
embedded software for a commercial device. Either way the hope is for this
project to provide clear and concise information to inspire and enable
people to to learn and do more. I know I learned a lot from this effort, and
if any of that can be shared and help others out that would be great.

For a starting point on additional details and the accomplishments and future
intentions of this project please see the Subprojects section below.
